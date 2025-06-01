#include <iostream>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    // 设置服务器套接字为非阻塞模式
    int flags = fcntl(server_fd, F_GETFL, 0);
    // fcntl(server_fd, F_SETFL, flags | O_NONBLOCK);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(1145);

    if (bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 10) == -1) {
        perror("listen");
        close(server_fd);
        return 1;
    }

    std::cout << "Server is listening on port 1145..." << std::endl;

    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (client_fd == -1) {
        perror("accept");
        close(server_fd);
        return 1;
    }

    // 设置客户端套接字为非阻塞模式
    flags = fcntl(client_fd, F_GETFL, 0);
    // fcntl(client_fd, F_SETFL, flags | O_NONBLOCK);

    std::cout << "Client connected." << std::endl;

    char buffer[1024];
    while (true) {
        ssize_t bytes_read = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            std::cout << "Received: " << buffer << std::endl;
        } else if (bytes_read == 0) {
            std::cout << "Client closed the connection." << std::endl;
            break;
        } else if (bytes_read == -1 && errno == EAGAIN) {
            perror("recv EAGAIN");
            std::cout << "No data available. Trying again later." << std::endl;
            // 可以在这里稍后再次尝试读取
        } else {
            perror("recv");
            break;
        }
        // 这里是尝试再次调用read操作（那么多行代码核心其实就是一个read），看看EAGAIN的错误
        //////////////////////////////////
        // size_t bytes_read = recv(client_fd, buffer, sizeof(buffer), 0);
        // if (bytes_read > 0) {
        //     buffer[bytes_read] = '\0';
        //     std::cout << "Received: " << buffer << std::endl;
        // } else if (bytes_read == 0) {
        //     std::cout << "Client closed the connection." << std::endl;
        //     break;
        // } else if (bytes_read == -1 && errno == EAGAIN) {
        //     perror("recv EAGAIN");
        //     std::cout << "No data available. Trying again later." << std::endl;
        //     // 可以在这里稍后再次尝试读取
        // } else {
        //     perror("recv");
        //     break;
        // }
        //////////////////////////////
    }

    close(client_fd);
    close(server_fd);
    return 0;
}



// 本示例内容：
//     fcntl设置nonblock的方法
//     errno错误码的使用
//     非阻塞状态下调用recv会立马返回错误码errno == EAGAIN


/*
    非阻塞套接字是在学习epoll的时候同时引入的概念，由于太多新的内容没来得及分清和理解，导致没有真正学明白，
    在不使用epoll标准的最佳实践代码的情况下，只有while(1)循环会导致非阻塞的套接字读取消息的时候反复执行，
    高频反复调用recv函数，不断输出错误信息EAGAIN到终端，所以需要合适代码分支逻辑来解决这个问题。
*/

/*
    非阻塞是针对于套接字本身来说的，不论是recv、send、accept、connect等函数调用，第一个函数参数是套接字，
    而此时这个套接字是非阻塞的，那么决定了这个函数调用的操作是非阻塞的。
*/

/*
    一个服务器连接了n个客户端套接字，其中可以一部分阻塞，一部分非阻塞，具体要看代码逻辑如何处理，包括服务器套接字本身。
    这里点出只是为了说明真实情况，为了强化本质认知，而并不是说这样的操作是最佳实践
*/
