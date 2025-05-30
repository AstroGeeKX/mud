// B3665 小清新数据结构题

// 若干条数据，每条数据是一个vector容器
// 数据输入每条第一个是数量，剩余的是具体的数据，如何处理数据输入
// lise[x][y] = temp会出现越界的问题，可能[] =赋值操作符并不会自动增长容量，要先使用resize确保不越界
// 题解的做法是创建3000000个元素的vector数组，但是我用嵌套vector

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// 将需要求按位异或和的数放在 vector 中传参。
unsigned int getXorSum(const std::vector<unsigned int>& rec) {
    unsigned ret = 0;
    for (int i = 0; i < rec.size(); ++i) ret ^= rec[i];
    return ret;
}

int main() {
    int n, s;  // n数据条数 s查询次数
    cin >> n >> s;
    vector<vector<unsigned int>> list(n);  // 嵌套类型，拟二维数组
    vector<unsigned int> result;  // 结果保存，方便使用上面的函数

    int size;  // 一条数据的个数
    unsigned int temp;  // 输入的临时数据，用temp即可，没什么特殊要求
    for (int i = 0; i < n; i++) {
        scanf("%d", &size);  // 如果用cin流会超时
        list[i].resize(size);  // resize之后才能保证[]访问不越界
        for (int j = 0; j < size; j++) {
            scanf("%u", &temp);
            list[i][j] = temp;
        }
    }

    // 输入查询
    int x, y;
    result.resize(s);  // 多少个查询，就有多少个结果
    for (int i = 0; i < s; i++) {
        scanf("%d %d", &x, &y);  // 查询位置x y类型是int，但查询结果数值是unsigned int
        result[i] = list[x - 1][y - 1];  // 下标0要减1的问题
    }

    cout << getXorSum(result) << endl;

    return 0;
}
