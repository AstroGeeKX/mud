#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int row, col;
    char arr[100][100];
    memset(arr, ' ', 100 * 100);
    char c;
    bool f;
    cin >> row >> col >> c >> f;
    if (f == 1)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = c;
            }
        }
    }

    //  f == 0
    for (int j = 0; j < col; j++)
    {
        arr[0][j] = arr[row - 1][j] = c;
    }
    for (int i = 0; i < row; i++)
    {
        arr[i][0] = arr[i][col - 1] = c;
    }

    // 打印
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}