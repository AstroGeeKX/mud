#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inFile("input.txt");
    if (!inFile) {
        std::cerr << "无法打开输入文件" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        // 查找音标部分的起始和结束位置
        size_t start = line.find('[');
        size_t end = line.find(']');
        if (start!= std::string::npos && end!= std::string::npos) {
            line.erase(start, end - start + 1);
        }
        std::cout << line << std::endl;
    }
    inFile.close();
    return 0;
}