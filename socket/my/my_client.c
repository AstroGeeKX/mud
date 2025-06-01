#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 10000
#define BUFFSIZE 1024

int main() {
  int client_socket;
  struct sockaddr_in client_addr;
  char buffer[BUFFSIZE] = {0};
  ssize_t bytes_read = 0;  // read的返回值，也可以用int类型

  // 创建套接字
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == 0) {
    perror("socket failed");
    exit(1);
  }

  // 设置服务器地址
  memset(&client_addr, 0, sizeof(client_addr));
  client_addr.sin_family = AF_INET;
  client_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  client_addr.sin_port = htons(PORT);

  // 连接到服务器
  if (connect(client_socket, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
    perror("connect failed");
    exit(1);
  }

  printf("please enter message send to server\n");
  // 发送和接收数据
  while (1) {
    // scanf("%s", buffer);  // fgets()会多一个'\n'，意味着多1个字节
    fgets(buffer, sizeof(buffer), stdin);  // 这里获取命令行输入 fgets()会吸收回车
    write(client_socket, buffer, strlen(buffer));  // write的发送字节数一定要写对，发多少写多少
    // printf 发送了多少个字节
    bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);  // 读满 结尾 空字符 在这里读取消息 ///////
    // continue;
    if (bytes_read > 0 ) {
      buffer[bytes_read] = '\0';  // 结尾置空字符
      printf("echo: %s", buffer);
    } else if (bytes_read == 0) {
      printf("connection is closed\n");
      close(client_socket);
      exit(1);  // exit(1)也就是exit(EXIT_FAILURE)，只是个宏定义
    } else if (bytes_read == -1 && errno == EAGAIN) {  // EAGAIN 只是缓冲区没有内容可读，不是真正的错误
      perror("read EAGAIN");
      continue;
    } else if (bytes_read == -1 && errno != EAGAIN) {  // 出现error并且不是EAGAIN，是真正的错误
      perror("read");
      close(client_socket);
      exit(1);
    }
  }

  // 关闭连接
  close(client_socket);

  return 0;
}


// 这是一个成功的socket客户端代码实践
// 写起来还是很有意思的，把错误处理写得比较整齐
// 遇到的最大的一个问题是write的size写错成了sizeof(buffer)，正确的是strlen(buffer)
// 发多少个字节就写多少个，而不是把整个1024字节全部写上去，发送和接收的字节意义不一样

// 4月30日 再实现一个echo，就告一段落了，继续看视频教程
