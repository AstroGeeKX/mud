#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9000);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(listenfd, 32);

    fd_set allset, rset;
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);
    int maxfd = listenfd;

    while (1) {
        rset = allset;
        int nReady = select(maxfd + 1, &rset, NULL, NULL, NULL);
        if (FD_ISSET(listenfd, &rset)) {
            struct sockaddr_in clientaddr;
            socklen_t len = sizeof(clientaddr);
            int connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &len);
            FD_SET(connfd, &allset);
            if (connfd > maxfd) maxfd = connfd;
            if (--nReady <= 0) continue;
        }
        for (int i = 0; i <= maxfd; i++) {
            if (FD_ISSET(i, &rset)) {  // 防止对监听套接字进行read操作 i != listenfd && FD_ISSET(i, &rset)
                char buf[1024] = {0};
                int nread = read(i, buf, sizeof(buf));
                if (nread == 0) {
                    close(i);
                    FD_CLR(i, &allset);
                } else {
                    write(i, buf, nread);
                }
                if (--nReady <= 0) break;
            }
        }
    }
    return 0;
}

/*
    select示例代码，服务器端
    这个代码比较标准，可以作为代码模板
    摘录CSDN
*/

// socket + listen是监听套接字
// accept已连接套接字
