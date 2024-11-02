// epoll大致模板// epoll大致模板// epoll大致模板
// epoll大致模板// epoll大致模板// epoll大致模板
struct epoll_event ev, events[MAX_EVENTS];

// 创建epoll实例
int epoll_fd = epoll_create1(0);

// 添加监听套接字到epoll兴趣列表
ev.events = EPOLLIN;
ev.data.fd = listen_sockfd;
epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_sockfd, &ev);

// 事件循环
while (1)
{
    int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
    for (int n = 0; n < nfds; ++n)
    {
        if (events[n].events & EPOLLIN)
        {
            if (events[n].data.fd == listen_sockfd)
            {
                // 接受新的连接
            }
            else
            {
                // 处理数据读取
            }
        }
        // 处理其他事件...
    }
}
// epoll大致模板// epoll大致模板// epoll大致模板
// epoll大致模板// epoll大致模板// epoll大致模板

// events数组代表的是触发的事件，而不是兴趣事件，兴趣事件是看不到的
// 每次调用wait都会返回新的数组，提前结束循环就可能遗漏掉触发的事件


/*创建客户端套接字，并放入epoll兴趣列表中*//*创建客户端套接字，并放入epoll兴趣列表中*/
/*创建客户端套接字，并放入epoll兴趣列表中*//*创建客户端套接字，并放入epoll兴趣列表中*/
struct sockaddr_in clnt_addr;
bzero(&clnt_addr, sizeof(clnt_addr));
socklen_t clnt_addr_len = sizeof(clnt_addr);

int clnt_sockfd = accept(sockfd, (sockaddr *)&clnt_addr, &clnt_addr_len);

printf("new client fd %d! IP: %s Port: %d\n", clnt_sockfd, inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));

bzero(&ev, sizeof(ev));
ev.data.fd = clnt_sockfd;
ev.events = EPOLLIN | EPOLLET;
setnonblocking(clnt_sockfd);
epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sockfd, &ev);
/*创建客户端套接字，并放入epoll兴趣列表中*//*创建客户端套接字，并放入epoll兴趣列表中*/
/*创建客户端套接字，并放入epoll兴趣列表中*//*创建客户端套接字，并放入epoll兴趣列表中*/