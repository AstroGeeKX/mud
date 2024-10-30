// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <random>
// #include <algorithm>

// using namespace std;

// int main() {
//     // 读取单词表
//     vector<string> words;
//     ifstream infile("vocabulary.txt.md");
//     string word;
//     while (getline(infile, word)) {
//         words.push_back(word);
//     }
//     infile.close();

//     // 随机提取100个单词
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> distrib(0, words.size() - 1);
//     vector<string> randomWords;
//     for (int i = 0; i < 100; i++) {
//         int index = distrib(gen);
//         randomWords.push_back(words[index]);
//     }

//     // 输出随机单词
//     cout << "随机提取的100个单词：" << endl;
//     for (const string& word : randomWords) {
//         cout << word << endl;
//     }

//     // 保存随机单词到文件
//     ofstream outfile("random_words.txt.md");
//     for (const string& word : randomWords) {
//         outfile << word << endl;
//     }
//     outfile.close();

//     return 0;
// }



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cctype>
#include <filesystem>

using namespace std;

// 函数用于查找已有的最大序号
int findMaxNumber() {
    filesystem::path directoryPath(".");
    vector<int> numbers;
    for (const auto & entry : filesystem::directory_iterator(directoryPath)) {
        string filename = entry.path().filename().string();
        if (filename.find("random_words_") == 0) {
            string numberStr = filename.substr(13); // 假设前缀"random_words_"长度为13
            numberStr.erase(remove_if(numberStr.begin(), numberStr.end(), ::ispunct), numberStr.end());
            if (!numberStr.empty()) {
                numbers.push_back(stoi(numberStr));
            }
        }
    }
    if (!numbers.empty()) {
        return *max_element(numbers.begin(), numbers.end()) + 1;
    } else {
        return 1; // 如果没有找到任何匹配的文件，从1开始
    }
}

int main() {
    // 读取单词表
    vector<string> words;
    ifstream infile("vocabulary.txt.md");
    string word;
    while (getline(infile, word)) {
        words.push_back(word);
    }
    infile.close();

    // 随机提取100个单词
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, words.size() - 1);
    vector<string> randomWords;
    for (int i = 0; i < 100; i++) {
        int index = distrib(gen);
        randomWords.push_back(words[index]);
    }

    // 确定新的文件名
    int newNumber = findMaxNumber();
    string outputFilename = "random_words_" + to_string(newNumber) + ".txt.md";

    // 输出随机单词到文件
    ofstream outfile(outputFilename);
    for (const string& word : randomWords) {
        outfile << word << endl;
    }
    outfile.close();

    return 0;
}