//     // 保存随机单词到文件
//     ofstream outfile("random_words.txt.md");
//     for (const string& word : randomWords) {
//         outfile << word << endl;
//     }
//     outfile.close();

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define N 10000

int main() {
    ofstream outfile("if_list.cpp");
    for (int i = 0; i < N; i++) {
        outfile << "    if (i == " << i << ") { cout << i; }" << endl;    
    }
    
    outfile.close();
    return 0;
}

// 生成很多条if-else语句
