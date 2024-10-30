// #include <iostream>
// using namespace std;

// int main()
// {
//     // 测试验证 无符号变量算式结果为负数，实际上是从最高数值溢出
//     unsigned short us1 = 0;
//     unsigned short us2 = 5;
//     unsigned short us3 = 10;
//     unsigned short us4 = us1 - us2;
//     cout << us4;
//     return 0;
// }

// 天工代码，动态内存分配 
#include <iostream>
#include <vector>

void addData(std::vector<std::vector<int>>& dataContainer, int groupId, int data) {
    // 如果数据组不存在，创建一个新的数据组
    if (groupId >= dataContainer.size()) {
        dataContainer.resize(groupId + 1);
    }
    // 将数据添加到指定的数据组
    dataContainer[groupId].push_back(data);
}

int main() {
    std::vector<std::vector<int>> dataContainer;

    // 添加数据到不同的数据组
    addData(dataContainer, 0, 1); // 添加到第一个数据组
    addData(dataContainer, 0, 2); // 继续添加到第一个数据组
    addData(dataContainer, 1, 3); // 添加到第二个数据组
    addData(dataContainer, 2, 4); // 添加到第三个数据组

    // 打印所有数据组
    for (size_t i = 0; i < dataContainer.size(); ++i) {
        std::cout << "Data Group " << i + 1 << ": ";
        for (int elem : dataContainer[i]) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}