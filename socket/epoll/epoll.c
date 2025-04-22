#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>

#define MAX_EVENTS 1024
#define BUFFER_SIZE 4096
#define PORT 8080

// 设置文件描述符为非阻塞模式
static void set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

// 处理客户端数据
static void handle_client_data(int client_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t n = recv(client_fd, buffer, sizeof(buffer), 0);

    if (n > 0) {
        // 模拟业务逻辑：回显数据
        send(client_fd, buffer, n, 0);
    } else if (n == 0 || (n == -1 && errno != EAGAIN)) {
        // 客户端关闭连接或出错
        close(client_fd);
        printf("客户端 %d 断开连接\n", client_fd);
    }
    // n == -1 && errno == EAGAIN: 数据未就绪，忽略
}

int main() {
    int server_fd, epoll_fd;
    struct sockaddr_in server_addr;
    struct epoll_event ev, events[MAX_EVENTS];

    // 1. 创建 TCP Socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // 2. 设置 SO_REUSEADDR 避免 TIME_WAIT 状态占用端口
    int reuse = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    // 3. 绑定地址和端口
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind() failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 4. 设置非阻塞并开始监听
    set_nonblocking(server_fd);
    listen(server_fd, SOMAXCONN);

    // 5. 创建 epoll 实例
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1() failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 6. 将 server_fd 加入 epoll 监听队列（边缘触发模式）
    ev.events = EPOLLIN | EPOLLET; // 边缘触发 + 可读事件
    ev.data.fd = server_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &ev) == -1) {
        perror("epoll_ctl(server_fd) failed");
        close(server_fd);
        close(epoll_fd);
        exit(EXIT_FAILURE);
    }

    printf("服务器启动，监听端口 %d...\n", PORT);

    // 7. 事件循环
    while (1) {
        int nready = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (nready == -1) {
            if (errno == EINTR) continue; // 被信号中断，忽略
            perror("epoll_wait() failed");
            break;
        }

        for (int i = 0; i < nready; i++) {
            int fd = events[i].data.fd;

            // 处理新连接
            if (fd == server_fd) {
                // 边缘触发模式下必须一次性 accept 所有连接
                while (1) {
                    struct sockaddr_in client_addr;
                    socklen_t addrlen = sizeof(client_addr);
                    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addrlen);

                    if (client_fd == -1) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK) break; // 无更多连接
                        perror("accept() failed");
                        continue;
                    }

                    // 设置新连接为非阻塞
                    set_nonblocking(client_fd);
                    printf("新客户端连接: fd=%d\n", client_fd);

                    // 将 client_fd 加入 epoll（边缘触发模式）
                    ev.events = EPOLLIN | EPOLLET | EPOLLRDHUP; // 监听可读、连接关闭事件
                    ev.data.fd = client_fd;
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev) == -1) {
                        perror("epoll_ctl(client_fd) failed");
                        close(client_fd);
                    }
                }
            } 
            // 处理客户端数据或连接关闭
            else {
                if (events[i].events & EPOLLRDHUP) {
                    // 对端关闭连接
                    close(fd);
                    printf("客户端 %d 断开连接\n", fd);
                } else if (events[i].events & EPOLLIN) {
                    handle_client_data(fd);
                }
            }
        }
    }

    // 清理资源（实际不会执行到这里）
    close(server_fd);
    close(epoll_fd);
    return 0;
}

// 标准的epoll模板
// 来源deepseek AI
