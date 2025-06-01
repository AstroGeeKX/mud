#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>

#define MAX_CLIENTS 1024
#define BUFFER_SIZE 4096
#define PORT 8080

// 设置文件描述符为非阻塞模式（Windows下的模拟）
static void set_nonblocking(SOCKET sock) {
    unsigned long mode = 1;
    ioctlsocket(sock, FIONBIO, &mode);
}

// 处理客户端数据
static void handle_client_data(SOCKET client_sock) {
    char buffer[BUFFER_SIZE];
    int n = recv(client_sock, buffer, sizeof(buffer), 0);

    if (n > 0) {
        // 模拟业务逻辑：回显数据
        send(client_sock, buffer, n, 0);
    } else if (n == 0) {
        // 客户端关闭连接
        closesocket(client_sock);
        printf("客户端 %d 断开连接\n", client_sock);
    } else if (n == SOCKET_ERROR) {
        int error = WSAGetLastError();
        if (error!= WSAEWOULDBLOCK) {
            // 出错（非数据未就绪情况）
            closesocket(client_sock);
            printf("客户端 %d 出错断开连接\n", client_sock);
        }
    }
    // n == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK: 数据未就绪，忽略
}

int main() {
    WSADATA wsaData;
    SOCKET server_sock, client_socks[MAX_CLIENTS];
    struct sockaddr_in server_addr;
    fd_set read_fds;
    int max_sock = 0;
    int i;

    // 初始化Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData)!= 0) {
        perror("WSAStartup() failed");
        return 1;
    }

    // 1. 创建 TCP Socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == INVALID_SOCKET) {
        perror("socket() failed");
        WSACleanup();
        return 1;
    }

    // 2. 设置 SO_REUSEADDR（Windows下设置方式不同）
    // BOOL reuse = TRUE;
    // setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse));

    // 3. 绑定地址和端口
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        perror("bind() failed");
        closesocket(server_sock);
        WSACleanup();
        return 1;
    }

    // 4. 设置非阻塞并开始监听
    set_nonblocking(server_sock);
    listen(server_sock, SOMAXCONN);

    // 初始化客户端套接字数组
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_socks[i] = INVALID_SOCKET;
    }

    printf("服务器启动，监听端口 %d...\n", PORT);

    // 5. 事件循环（使用select模拟epoll）
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_sock, &read_fds);
        max_sock = server_sock;

        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_socks[i]!= INVALID_SOCKET) {
                FD_SET(client_socks[i], &read_fds);
                if (client_socks[i] > max_sock) {
                    max_sock = client_socks[i];
                }
            }
        }

        int nready = select(max_sock + 1, &read_fds, NULL, NULL, NULL);
        if (nready == SOCKET_ERROR) {
            perror("select() failed");
            break;
        }

        if (FD_ISSET(server_sock, &read_fds)) {
            // 处理新连接
            while (1) {
                struct sockaddr_in client_addr;
                int client_addr_len = sizeof(client_addr);
                SOCKET client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len);
                if (client_sock == INVALID_SOCKET) {
                    if (WSAGetLastError() == WSAEWOULDBLOCK) break;
                    perror("accept() failed");
                    continue;
                }

                // 设置新连接为非阻塞
                set_nonblocking(client_sock);

                // 找到空闲的客户端数组位置并保存新连接
                for (i = 0; i < MAX_CLIENTS; i++) {
                    if (client_socks[i] == INVALID_SOCKET) {
                        client_socks[i] = client_sock;
                        printf("新客户端连接: fd=%d\n", client_sock);
                        break;
                    }
                }
                if (i == MAX_CLIENTS) {
                    // 客户端数组已满，关闭新连接
                    closesocket(client_sock);
                    printf("客户端数组已满，拒绝新连接\n");
                }
            }
        }

        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_socks[i]!= INVALID_SOCKET && FD_ISSET(client_socks[i], &read_fds)) {
                // if (handle_client_data(client_socks[i]) == -1) {
                    // 处理客户端数据出错或连接关闭
                    // closesocket(client_socks[i]);
                    // client_socks[i] = INVALID_SOCKET;
                    // printf("客户端 %d 断开连接\n", client_socks[i]);
                // }
                handle_client_data(client_socks[i]);
            }
        }
    }

    // 清理资源
    closesocket(server_sock);
    WSACleanup();
    return 0;
}
