#if 0
#include <csignal>
#include <iostream>
#include <windows.h>

using namespace std;

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";

    exit(signum);  // 清理并终止程序
}

int main() {
    signal(SIGINT, signalHandler);  // 注册信号 SIGINT 和信号处理程序

    while (1) {
        cout << "Going to sleep...." << endl;
        Sleep(500);
    }

    return 0;
}
#endif


#include <iostream>
#include <csignal>
#include <windows.h>

using namespace std;

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

int main() {
    int i = 0;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    while (++i) {
        cout << "Going to sleep...." << endl;
        if (i == 3) {
            raise(SIGINT);  // 发出INT中断信号
        }
        Sleep(100);
    }

    return 0;
}
