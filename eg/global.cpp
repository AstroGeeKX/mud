#include <iostream>
#include <cstring>
#include <cstdio>
#include <chrono>

using namespace std;

// 定义用
#define START auto start = chrono::high_resolution_clock::now()
#define END auto end = chrono::high_resolution_clock::now()
#define DURATION auto duration = chrono::duration_cast<chrono::microseconds>(end - start)
// 再次用
#define START_ start = chrono::high_resolution_clock::now()
#define END_ end = chrono::high_resolution_clock::now()
#define DURATION_ duration = chrono::duration_cast<chrono::microseconds>(end - start)

// 内存大小宏定义
#define MYSIZE 2000000  // 大小2mb
#define E50 50000000000  // 大小50gb

char g_p[MYSIZE];  // 全局变量数组

int main() {
    char s_p[MYSIZE];              // 栈区变量数组
    char *h_p = new char[MYSIZE];  // heap区变量数组
    
    char t = 0;  // 临时变量

    START;
    for (size_t i = 0; i < MYSIZE; i++) {
        t = s_p[i];  // 读访问
        // if (i % 100000000 == 0) {
        //     printf("i: %lld &p[i]: %p\n", i, &p[i]);
        // }
    }
    END;
    DURATION;
    cout << "stack spend time(us): " << duration.count() << endl;

    START_;
    for (size_t i = 0; i < MYSIZE; i++) {
        t = h_p[i];  // 读访问
    }
    END_;
    DURATION_;
    cout << "heap spend time(us): " << duration.count() << endl;

    START_;
    for (size_t i = 0; i < MYSIZE; i++) {
        t = g_p[i];  // 读访问
    }
    END_;
    DURATION_;
    cout << "global spend time(us): " << duration.count() << endl;

    delete[] h_p;

    return 0;
}

// main栈 2070000 byte 2070kb 2mb
// global 虽然能创建100gb的数组，实际运行最高有效是1.2gb左右
// heap 50000070000 byte 50gb。32gb的内存条满，虚拟内存c盘空间增大12gb多

/*
    栈、堆、全局 速度测试
    stack spend time(us): 3827    1.9ns
    heap spend time(us): 4032
    global spend time(us): 4269   2.1ns
*/

/*
    空循环1.66ns一次
*/

/*
    6月4日差不多就到这里，研究了栈、堆、全局区的数据
*/
