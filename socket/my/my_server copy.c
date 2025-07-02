#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void printMemory(const char *buffer_, int length);

// #define SERVER_IP INADDR_ANY
#define PORT 10000
#define BUFFERSIZE 1024

int main() {
  int listen_socket;
  struct sockaddr_in server_addr;
  char buffer[BUFFERSIZE] = {0};
  ssize_t bytes_read = 0;

  // 创建套接字
  listen_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_socket == 0) {
    perror("socket failed");
    exit(1);
  }

  // 设置服务器地址
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // 绑定地址 （错误处理）
  bind(listen_socket, (struct sockaddr *)&server_addr,
       sizeof(server_addr));

  // 开启监听
  if (listen(listen_socket, 128) < 0) {
    perror("listen failed");
    exit(1);
  } else {
    printf("服务器已开启监听...\n");
  }

  // 创建客户端连接
  int client_socket;
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  memset(&client_addr, 0, sizeof(client_addr));

  client_socket = accept(listen_socket,
                         (struct sockaddr *)&client_addr,
                         &client_addr_len);
  if (client_socket < 0) {
    perror("accept failed");
    close(listen_socket);
    exit(1);
  } else {
    printf("客户端已连接 fd：%d 端口：%d\n",client_socket,
           ntohs(client_addr.sin_port));
  }

  // 接发消息
  while (1) {
    bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
      buffer[bytes_read] = '\0';  // 结尾置空字符
      write(client_socket, buffer, bytes_read);  // 收到的消息重新发回客户端

    ////////////////////错误处理///////////////////
    } else if (bytes_read == 0) {
      printf("connection is closed, depends on read()\n");
      close(listen_socket);
      close(client_socket);
      exit(1);
    } else if (bytes_read == -1 && errno == EAGAIN) {  // EAGAIN是缓冲区没有内容可读，重试
      perror("read EAGAIN");
      continue;
    } else if (bytes_read == -1 && errno != EAGAIN) {  // 错误
      perror("read");
      close(listen_socket);
    }
  }

  // 关闭连接
  close(listen_socket);

  return 0;
}

// 服务器实现
// 写起来还是很有意思的，把错误处理写得比较整齐
// 遇到的最大的一个问题是write的size写错成了sizeof(buffer)，正确的是strlen(buffer)
// 发多少个字节就写多少个，而不是把整个1024字节全部写上去，发送和接收的字节意义不一样

// 打印字符串之后的内存，当作是内存监视器
void printMemory(const char *buffer_, int length) {
  printf("  printMemory: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", *buffer_);
    buffer_++;
  }
  printf("\n");
}


/* 4月30日内容
  fputs(buffer, stdout);
  fflush(stdout);
  // 直接打印消息，并且缓冲区刷新，体验TCP字节流
  // 如果没有fflush，消息不会打印，而是在stdout缓冲区内积累满1024个字节才打印
*/

/* 4月30日
  现在是2:23，刚刚已经完成echo的测试，用了十分稳妥的方法，
  fgets()和多次write()来完成echo消息。期间发生了一个错误，
  write()中的fd错写成了listenfd，而不是clientfd，导致程序错误关闭

*/
