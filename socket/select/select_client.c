#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9000);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    char recvline[1024], writeline[1024];
    while (1) {
        memset(recvline, 0, sizeof(recvline));
        memset(writeline, 0, sizeof(writeline));
        printf("send to server: ");
        fgets(writeline, sizeof(writeline), stdin);
        write(sockfd, writeline, strlen(writeline));
        int len = read(sockfd, recvline, sizeof(recvline));
        if (len == 0) {
            printf("server is close\n");
            break;
        }
        printf("receive from server: %s\n", recvline);
    }
    close(sockfd);
    return 0;
}

/*
    select客户端代码示例
    摘录CSDN
*/