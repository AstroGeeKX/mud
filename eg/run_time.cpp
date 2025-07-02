#include <iostream>
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

#define NUM 100000

int main() {
    const size_t n = 1000;
    size_t t = 10;  // 临时变量

    START;
    for (size_t i = 0; i < NUM; i++) {
        cout << "cout ";
        printf("printf ");
    }
    END;
    DURATION;
    cout << "\nspend time: " << duration.count() << "us  "
         << duration.count() / 1000 << "ms" << endl;

    return 0;
}

/*
 很奇怪，cout比printf快6.7倍
*/
