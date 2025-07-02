/*
 * Linux下基于Reactor模式的高并发HTTP服务器
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <functional>
#include <string>
#include <iostream>
#include "ThreadPool.h"

#define MAX_EVENTS 1024
#define BUFFER_SIZE 1024
#define PORT 10000

void headers(int client);
void not_found(int client);
void response(int client, const char *filename);
void handle_read(int clnt_sock);
int init_listen();
void acceptor(int sockfd_, int epfd_);
void event_loop(int sockfd, int epfd);
int init_epoll(int sockfd);
bool parseHttpRequestInfo3(const std::string& httpRequest, std::string& method,
                           std::string& uri, std::string& version);

// 设置套接字为非阻塞
void set_nonblocking(int fd) {
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);
}

// 函数原型要一致，然后找函数原型在哪里，在<>里
static std::function<void(struct sockaddr_in addr)> on_connect_callback;

ThreadPool *threadpool = new ThreadPool();  // 全局线程池

int main() {
    std::function<void(struct sockaddr_in addr)> cb = ([](struct sockaddr_in addr) {
        printf("new client IP: %s Port: %d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        });
    on_connect_callback = std::move(cb);  // 新连接时的回调函数
    
    int sockfd = init_listen();

    int epfd = init_epoll(sockfd);

    event_loop(sockfd, epfd);

    return 0;
}

int init_listen() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    set_nonblocking(sockfd);  // 设置非阻塞

    // 设置 SO_REUSEADDR 避免 TIME_WAIT 状态占用端口
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if (bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // 套接字监听
    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("服务器在端口[%d]监听\n", ntohs(serv_addr.sin_port));

    return sockfd;
}

int init_epoll(int sockfd) {
    int epfd = epoll_create1(0);
    struct epoll_event ev;
    bzero(&ev, sizeof(ev));
    ev.data.fd = sockfd;
    ev.events = EPOLLIN | EPOLLET;
    epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);

    return epfd;
}

void acceptor(int sockfd_, int epfd_) {
    int clnt_sockfd;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_len = sizeof(clnt_addr);
    struct epoll_event ev;
    bzero(&clnt_addr, sizeof(clnt_addr));
    bzero(&ev, sizeof(ev));

    while (1) {
        // 接受新客户端连接
        clnt_sockfd = accept(sockfd_, (sockaddr*)&clnt_addr, &clnt_addr_len);
        if (clnt_sockfd == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break;
            } else {
                perror("accept() failed");
                continue;
            }
        }
        set_nonblocking(clnt_sockfd);   // 设置客户端套接字非阻塞
        ev.data.fd = clnt_sockfd;       // ev结构体设置fd
        ev.events = EPOLLIN | EPOLLET;  // ev结构体设置events，即监听事件类型，不要再强调语义了
        epoll_ctl(epfd_, EPOLL_CTL_ADD, clnt_sockfd, &ev);
        // lambda表达式
        on_connect_callback(clnt_addr);
    }
}

void event_loop(int sockfd, int epfd) {
    struct epoll_event eventsList[MAX_EVENTS];
    // 事件循环
    while (true) {
        int nfds = epoll_wait(epfd, eventsList, MAX_EVENTS, -1);
        if (nfds == -1) {
            if (errno == EINTR) continue; // 被信号中断，忽略
            perror("epoll_wait() failed");
            break;
        }

        for (int i = 0; i < nfds; i++) {
            int fd = eventsList[i].data.fd;
            if (fd == sockfd) {
                acceptor(sockfd, epfd);
            } else if (eventsList[i].events & EPOLLIN) {
                threadpool->add([=]() { handle_read(fd); });
            } else if (eventsList[i].events & EPOLLRDHUP) {
                // 对端关闭连接 目前还不知道RDHUP有什么用
                close(fd);
                printf("RDHUP 客户端 %d 断开连接\n", fd);
            }
            // 其他类型的事件 eventsList[i].events & EPOLLOUT
        }
    }
}

void handle_read(int clnt_sock_) {
    char readBuffer_[BUFFER_SIZE] = {0};
    std::string requestHeader;
    std::string method;
    std::string uri;
    std::string version;
    while (true) {
        int bytes_read = read(clnt_sock_, readBuffer_, sizeof(readBuffer_) - 1);
        // 业务处理
        if (bytes_read > 0) {
            requestHeader = readBuffer_;  // 拷贝请求头到string对象
            readBuffer_[bytes_read] = '\0';
        } else if(bytes_read == 0) {
            printf("EOF, client fd %d disconnected\n", clnt_sock_);
            close(clnt_sock_);
            break;
        } else if (bytes_read < 0 && errno == EAGAIN) {
            parseHttpRequestInfo3(requestHeader, method, uri, version);  // 解析请求行
            // fputs(readBuffer_, stdout);      // 打印请求
            std::cout << "method: " << method << std::endl;
            std::cout << "uri: " << uri << std::endl;
            std::cout << "version: " << version << std::endl;
            std::cout << std::endl;
            response(clnt_sock_, uri.c_str());  // 响应
            break;  // EAGAIN是读完消息了,读完消息了响应消息，然后break循环
        } else if (bytes_read < 0 && errno != EAGAIN) {
            perror("read() faild");  // 发生错误
            break;
        }
    }
}

void headers(int client) {
  char buf[1024] = {0};

  sprintf(buf, "HTTP/1.0 200 OK\r\n");
  send(client, buf, strlen(buf), 0);
  sprintf(buf, "Content-Type: text/html\r\n");
  send(client, buf, strlen(buf), 0);
  sprintf(buf, "\r\n");
  send(client, buf, strlen(buf), 0);
}

void response(int client, const char *filename) {
  char buf[1024] = {0};
  FILE *resource = fopen(filename + 1, "r");  // + 1是为了去除uri携带的/

  if (!resource) {
    perror("找不到文件");
    not_found(client);
    return;
  }

  headers(client);  // 200

  fgets(buf, sizeof(buf), resource);
  while (!feof(resource)) {
    send(client, buf, strlen(buf), 0);
    fgets(buf, sizeof(buf), resource);
  }
}

void not_found(int client)
{
    char buf[1024];

    sprintf(buf, "HTTP/1.0 404 NOT FOUND\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<HTML><TITLE>Not Found</TITLE>\r\n");
    send(client, buf, strlen(buf), 0);
    sprintf(buf, "<BODY><h1>404 NOT FOUND</h1>\r\n");
    send(client, buf, strlen(buf), 0);
    // sprintf(buf, "your request because the resource specified\r\n");
    // send(client, buf, strlen(buf), 0);
    // sprintf(buf, "is unavailable or nonexistent.\r\n");
    // send(client, buf, strlen(buf), 0);
    sprintf(buf, "</BODY></HTML>\r\n");
    send(client, buf, strlen(buf), 0);
}

bool parseHttpRequestInfo3(const std::string& httpRequest, std::string& method, std::string& uri, std::string& version) {
    if (httpRequest.empty()) {
        return false;
    }

    // 查找请求行的结束位置（第一个 \r\n）
    int pos = httpRequest.find("\r\n");
    if (pos == std::string::npos) {
        return false; // 如果没有找到 \r\n，则请求行格式有问题
    }
    std::string strRequestHead = httpRequest.substr(0, pos); // 抹去\r\n
    // 去除请求行两端的空白字符
    size_t start = strRequestHead.find_first_not_of(" \t\r\n");
    size_t end = strRequestHead.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos || start > end) {
        return false; // 请求行格式不对
    }
    strRequestHead = strRequestHead.substr(start, end - start + 1); // 抹去左右两端的空白字符

    // 解析 method    开头部分只需要算end
    size_t method_end = strRequestHead.find(' ');
    if (method_end == std::string::npos) {
        return false; // 请求行格式错误，method后面一直没有空格
    }
    method = strRequestHead.substr(0, method_end - 0);

    // 解析 URI    中间部分只需要算start和end
    size_t uri_start = strRequestHead.find_first_not_of(' ', method_end);
    size_t uri_end = strRequestHead.find(' ', uri_start);
    if (uri_end == std::string::npos) {
        return false; // 请求行格式错误，uri后面一直没有空格
    }
    uri = strRequestHead.substr(uri_start, uri_end - uri_start);

    // 解析 version    结尾部分只需要算start
    size_t version_start = strRequestHead.find_first_not_of(' ', uri_end);
    version = strRequestHead.substr(version_start);
    
    // 进一步验证 version 格式 (HTTP/1.1)
    if (version.find("HTTP/") != 0) {
        return false; // version 应该以 "HTTP/" 开头
    }

    return true;
}
