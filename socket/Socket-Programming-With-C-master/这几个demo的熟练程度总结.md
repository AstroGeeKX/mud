实际上这几个demo已经看明白个大概了，不需要再多花时间打磨这几行代码了
socket的文件描述符创建和使用大同小异
理解文件传输的本质是逐行读取文件然后一股脑发送至缓冲区（硬盘速度），内核协议栈再调度网卡慢慢走网线
其实也没什么好理解的，耗费太多时间了