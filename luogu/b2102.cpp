// B2102 计算鞍点

// 本题难点在于横竖数组的转换，这里是比较难想的
// [行][列] 行下标不变，同一行，列下标不变，同一列
// 先确定列，再确定行，这是本题的思路

// 这要求对数组的结构有清晰的认知，c语言的二维数组，实际上是由一条连续笔直的一维数组，人为分段而成
// 每一段为一行，定长，换行堆叠，形成二维数组
// 假设一行5个元素，第6个元素，可以是基于总数组的第6个元素，也可以是基于二维数组的，第2行，第1个元素
// * * * * * * + - - - - -  一维总数组

// * * * * * *  二维数组
// + - - - - -

#include <iostream>

int main() {
    int array[5][5] = {0};
    int maxNumColIndex = 0;  // 行最大值下标
    bool notFound = 1;    
    
    // 输入数组
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> array[i][j];
        }
    }
    
    for (int r = 0; r < 5; r++) {  // 外层循环，表示5行
        bool isMin = 1;
        int *row_ptr = array[r];
        for (int i = 0; i < 5; i++) {
            // if (array[r][i] > array[r][maxNumColIndex]) {
            //     maxNumColIndex = i;
            // }

            // 能否用一个一维数组，简化整个过程呢 省去[r]，提交结果是正确的 AC
            if (row_ptr[i] > row_ptr[maxNumColIndex]) {
                maxNumColIndex = i;
            }
        }
        // 运行到这里，array[r][maxNumColIndex]是第r行最大的数字 列数为rowMaxIndex
        for (int j = 0; j < 5; j++) {  // j是检索下标，如果比选定下标r更小，那么r不是最小的
            if (array[j][maxNumColIndex] < array[r][maxNumColIndex]) {  // 把列给锁死，就是同一条列
                isMin = 0;
                break;
            }
        }

        if (isMin) {
            std::cout << r + 1 << " " <<  maxNumColIndex + 1 << " " << array[r][maxNumColIndex] << std::endl;
            notFound = 0;
        }
    }

    if (notFound) {
        std::cout << "not found" << std::endl;
    }

    return 0;
}
