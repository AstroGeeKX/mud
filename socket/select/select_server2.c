#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int serverSocket, clientSockets[MAX_CLIENTS], maxSockets, activity, i, valread;
    int opt = 1;
    struct sockaddr_in address;
    fd_set readfds;
    char buffer[BUFFER_SIZE];

    // Create server socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8888);

    // Bind the socket
    if (bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 8888\n");

    maxSockets = serverSocket;
    memset(clientSockets, 0, sizeof(clientSockets));

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(serverSocket, &readfds);

        for (i = 0; i < MAX_CLIENTS; i++) {
            int clientSocket = clientSockets[i];
            if (clientSocket > 0) {
                FD_SET(clientSocket, &readfds);
                if (clientSocket > maxSockets) {
                    maxSockets = clientSocket;
                }
            }
        }

        activity = select(maxSockets + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(serverSocket, &readfds)) {
            // Handle new connection
            int newSocket;
            socklen_t addrlen = sizeof(address);
            if ((newSocket = accept(serverSocket, (struct sockaddr*)&address, &addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            printf("New connection, socket fd is %d, ip is : %s, port : %d\n", newSocket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clientSockets[i] == 0) {
                    clientSockets[i] = newSocket;
                    break;
                }
            }
            // 这里增加clientSockets数组满了的错误处理
            // 并且还有一个优化--activity == 0 break;
        }

        for (i = 0; i < MAX_CLIENTS; i++) {
            int clientSocket = clientSockets[i];
            if (FD_ISSET(clientSocket, &readfds)) {
                // Handle data from client
                valread = read(clientSocket, buffer, BUFFER_SIZE);
                if (valread == 0) {
                    // Client disconnected
                    printf("Host disconnected, socket fd is %d\n", clientSocket);
                    close(clientSocket);
                    clientSockets[i] = 0;
                } else {
                    // Echo received message back to client
                    buffer[valread] = '\0';
                    printf("Received: %s", buffer);
                    send(clientSocket, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}

// https://blog.csdn.net/tilblackout/article/details/134491041

// 需要增加clientSockets数组满越界的情况
