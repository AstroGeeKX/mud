好的，以下列出 Linux 套接字编程中常用的函数原型，并附带简要说明：

* **`int socket(int domain, int type, int protocol);`**
* **`int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`**
* **`int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`**
* **`int listen(int sockfd, int backlog);`**
* **`int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);`**
* **`ssize_t send(int sockfd, const void *buf, size_t len, int flags);`**
* **`ssize_t recv(int sockfd, void *buf, size_t len, int flags);`**
* **`int close(int sockfd);`**

**1. 创建套接字**

* **`int socket(int domain, int type, int protocol);`**
    * **参数:**
        * `domain`: 套接字域，例如 `AF_INET` (IPv4)，`AF_INET6` (IPv6)
        * `type`: 套接字类型，例如 `SOCK_STREAM` (面向连接的)，`SOCK_DGRAM` (无连接的)
        * `protocol`: 协议，通常为 `0`，表示使用默认协议
    * **返回值:** 成功时返回套接字描述符，失败时返回 `-1`。

**2. 地址转换**

* **`int inet_pton(int af, const char *src, void *dst);`**
    * **参数:**
        * `af`: 地址族，例如 `AF_INET` 或 `AF_INET6`
        * `src`: 字符串形式的 IP 地址
        * `dst`: 指向结构体 `in_addr` 或 `in6_addr` 的指针，用于存放转换后的二进制地址
    * **返回值:** 成功时返回 `1`，失败时返回 `0`，错误时返回 `-1`。

* **`const char *inet_ntop(int af, const void *src, char *dst, size_t size);`**
    * **参数:**
        * `af`: 地址族，例如 `AF_INET` 或 `AF_INET6`
        * `src`: 指向结构体 `in_addr` 或 `in6_addr` 的指针，用于存放二进制地址
        * `dst`: 指向字符数组的指针，用于存放转换后的字符串形式的 IP 地址
        * `size`: 字符数组的大小
    * **返回值:** 成功时返回指向 `dst` 的指针，失败时返回 `NULL`。

**3. 绑定地址**

* **`int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`**
    * **参数:**
        * `sockfd`: 套接字描述符
        * `addr`: 指向 `sockaddr` 结构体的指针，包含要绑定的地址信息
        * `addrlen`: 地址结构体的大小
    * **返回值:** 成功时返回 `0`，失败时返回 `-1`。

**4. 连接到服务器**

* **`int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`**
    * **参数:**
        * `sockfd`: 套接字描述符
        * `addr`: 指向 `sockaddr` 结构体的指针，包含服务器地址信息
        * `addrlen`: 地址结构体的大小
    * **返回值:** 成功时返回 `0`，失败时返回 `-1`。

**5. 监听连接**

* **`int listen(int sockfd, int backlog);`**
    * **参数:**
        * `sockfd`: 套接字描述符
        * `backlog`: 等待连接队列的最大长度
    * **返回值:** 成功时返回 `0`，失败时返回 `-1`。

**6. 接受连接**

* **`int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);`**
    * **参数:**
        * `sockfd`: 监听套接字描述符
        * `addr`: 指向 `sockaddr` 结构体的指针，用于存放客户端地址信息
        * `addrlen`: 地址结构体的大小
    * **返回值:** 成功时返回新的套接字描述符，失败时返回 `-1`。

**7. 发送数据**

* **`ssize_t send(int sockfd, const void *buf, size_t len, int flags);`**
    * **参数:**
        * `sockfd`: 套接字描述符
        * `buf`: 指向要发送数据的缓冲区的指针
        * `len`: 要发送数据的字节数
        * `flags`: 发送标志，例如 `MSG_DONTWAIT`
    * **返回值:** 成功时返回发送的字节数，失败时返回 `-1`。

* **`ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);`**
    * **参数:**
        * `sockfd`: 套接字描述符
        * `buf`: 指向要发送数据的缓冲区的指针
        * `len`: 要发送数据的字节数
        * `flags`: 发送标志
        * `dest_addr`: 指向 `sockaddr` 结构体的指针，包含目标地址信息
        * `addrlen`: 地址结构体的大小
    * **返回值:** 成功时返回发送的字节数，失败时返回 `-1`。

**8. 接收数据**

* **`ssize_t recv(int sockfd, void *buf, size_t len, int flags);`**
    * **参数:**
        * `sockfd`: 套接字描述符
        * `buf`: 指向接收数据的缓冲区的指针
        * `len`: 要接收数据的最大字节数
        * `flags`: 接收标志，例如 `MSG_DONTWAIT`
    * **返回值:** 成功时返回接收的字节数，失败时返回 `-1`。

* **`ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);`**
    * **参数:**
        * `sockfd`: 套接字描述符
        * `buf`: 指向接收数据的缓冲区的指针
        * `len`: 要接收数据的最大字节数
        * `flags`: 接收标志
        * `src_addr`: 指向 `sockaddr` 结构体的指针，用于存放发送方地址信息
        * `addrlen`: 地址结构体的大小
    * **返回值:** 成功时返回接收的字节数，失败时返回 `-1`。

**9. 关闭套接字**

* **`int close(int sockfd);`**
    * **参数:**
        * `sockfd`: 套接字描述符
    * **返回值:** 成功时返回 `0`，失败时返回 `-1`。


**10. 其他函数**

* **`int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);`**  获取套接字选项
* **`int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);`** 设置套接字选项
* **`int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen);`** 获取对端地址
* **`int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);`** 获取本地地址
* **`int shutdown(int sockfd, int how);`** 关闭套接字上的读写操作


**注意:**

* 以上函数原型仅列出了常用的函数，还有许多其他函数可供使用。
* 在实际编程中，需要根据具体情况选择合适的函数。
* 使用 `man` 命令可以查看每个函数的详细说明。


希望以上信息对您有所帮助。如果您还有其他问题，请随时提出。
