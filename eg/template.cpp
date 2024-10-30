#include <iostream>

template<int N>
void printNtimes(const char* str) {
    for(int i = 0; i < N; ++i) {
        std::cout << str << std::endl;
    }
}

int main() {
    printNtimes<3>("Hello World!");
    return 0;
}