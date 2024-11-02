/*客户端类*//*客户端类*//*客户端类*//*客户端类*//*客户端类*//*客户端类*/
class TcpClient
{
public:
    TcpClient();
    ~TcpClient();
    // int connectToHost(int fd, const char* ip, unsigned short port);
    int connectToHost(string ip, unsigned short port);

    // int sendMsg(int fd, const char* msg);
    int sendMsg(string msg);
    // int recvMsg(int fd, char* msg, int size);
    string recvMsg();
    
    // int createSocket();
    // int closeSocket(int fd);

private:
    // int readn(int fd, char* buf, int size);
    int readn(char* buf, int size);
    // int writen(int fd, const char* msg, int size);
    int writen(const char* msg, int size);
    
private:
    int cfd;	// 通信的套接字
};


/*服务器类*//*服务器类*//*服务器类*//*服务器类*//*服务器类*//*服务器类*/
class TcpServer
{
public:
    TcpServer();
    ~TcpServer();

    // int bindSocket(int lfd, unsigned short port) + int setListen(int lfd)
    int setListen(unsigned short port);
    // int acceptConn(int lfd, struct sockaddr_in *addr);
    int acceptConn(struct sockaddr_in *addr);

    // int sendMsg(int fd, const char* msg);
    int sendMsg(string msg);
    // int recvMsg(int fd, char* msg, int size);
    string recvMsg();
    
    // int createSocket();
    // int closeSocket(int fd);

private:
    // int readn(int fd, char* buf, int size);
    int readn(char* buf, int size);
    // int writen(int fd, const char* msg, int size);
    int writen(const char* msg, int size);
    
private:
    int lfd;	// 监听的套接字
    int cfd;	// 通信的套接字
};


// 注释在文件2.cpp有