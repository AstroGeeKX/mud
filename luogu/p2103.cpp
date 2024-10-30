// B2103 图像相似度

#include <iostream>
#include <cstdio>

using namespace std;

// 二维数组的特性，函数参数总是指针传递 int (*)matrix_f[100]
void inputMatrix(int matrix_f[100][100], int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> matrix_f[i][j];
        }
    }
}

int main()
{
    int matrix1[100][100] = {0};
    int matrix2[100][100] = {0};
    int sameCount = 0;
    int row = 0;
    int col = 0;
    cin >> row >> col;
    inputMatrix(matrix1, row, col);
    inputMatrix(matrix2, row, col);

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (matrix1[i][j] == matrix2[i][j])
            {
                sameCount += 1;
            }
        }
    }

    printf("%.2f", (double)sameCount / (row * col) * 100 );
    
    return 0;
}