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
  ssize_t bytes_read = 0;  // read的返回值，ssize_t类型是long int型

  // 创建套接字
  listen_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_socket == 0) {
    perror("socket failed");
    exit(1);
  }

  // 设置服务器地址
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;  // 意为接受来自所有IP段客户端的连接
  server_addr.sin_port = htons(PORT);

  // 绑定地址 （错误处理）
  bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
  
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
  socklen_t client_addr_len = sizeof(client_addr);  // 只有accept函数需要&client_addr_len 16个字节
  memset(&client_addr, 0, sizeof(client_addr));

  client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_socket < 0) {  // 客户端套接字创建失败
    perror("accept failed");
    printf("客户端套接字创建失败，目前服务器代码逻辑不支持第二次创建，故关闭服务器程序，请重新打开服务器\n");
    close(listen_socket);
    exit(1);
  } else {
    printf("客户端已连接 fd：%d 端口：%d\n",client_socket, ntohs(client_addr.sin_port));
  }

  // 接发消息
  while (1) {
    // memset(buffer, 0, sizeof(buffer));
    // scanf("%s", buffer);
    // fgets(buffer, sizeof(buffer), stdin);  // 这里获取命令行输入
    // sprintf(buffer, "12345");  // 将字符"12345"放入buffer里

    /*
      不加结尾空字符的情况：
      会读脏值，要加空字符在结尾，自己用个位数的bufsize测试

      接下来测试循环读满buffer，结尾空字符处理的情况
      读满n个，在buffer[n-1]的地方设置空字符，最后一个字符被'\0'覆盖造成损失
      读n - 1个，在buffet[n-1]个地方设置空字符，则没有字符损失，以便下一个循环继续读取，然后拼接字符串
      这里是有些基础教程还没有讲到的，估计是我的进度落下了吧
      :read根本没动[bytes_read, 10)范围的东西
      
      if第二个分支下面的内容是错误处理，不用看
      接收缓冲区满时，会多次read和write，直到清空数据
    */
    bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);  // 读满 结尾 空字符 在这里读取消息///////
    if (bytes_read > 0) {
      // --- 这里是读和写的代码，只看这里就够了 ----------------
      buffer[bytes_read] = '\0';  // 结尾置空字符
      // printf("client fd%d bytes_read %ld say: %s\n", client_socket, bytes_read, buffer);
      // printf("%s", buffer);
      fputs(buffer, stdout);
      fflush(stdout);
      if (write(client_socket, buffer, bytes_read) == -1) {  // write的发送字节数一定要写对，发个字节就多少写多少
        perror("write failed");
      }
      // --- 这里是读和写的代码，只看这里就够了 ----------------
    } else if (bytes_read == 0) {
      ////////////////////错误处理///////////////////
      printf("connection is closed, depends on read()\n");
      close(listen_socket);
      close(client_socket);
      exit(1);  // exit(1)也就是exit(EXIT_FAILURE)，只是个宏定义
    } else if (bytes_read == -1 && errno == EAGAIN) {  // EAGAIN错误 只是缓冲区没有内容可读，重试
      perror("read EAGAIN");
      continue;
    } else if (bytes_read == -1 && errno != EAGAIN) {  // 其余不是EAGAIN的错误，是真正的错误
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
