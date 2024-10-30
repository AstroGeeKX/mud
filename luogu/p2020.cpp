// p2020 分糖果游戏
// 这道题的盲点在于，糖果是先全部到手之后，才开始进行有序分配
#include <iostream>

using namespace std;

int main()
{
    int sugar[5] = {0};
    int eat = 0;
    cin >> sugar[0] >> sugar[1] >> sugar[2] >> sugar[3] >> sugar[4];

    for (int i = 0; i < 5; ++i)
    {
        eat += sugar[i] % 3;
        sugar[i] /= 3;
        sugar[(i + 1) % 5] += sugar[i]; // 后一个
        sugar[(i + 4) % 5] += sugar[i]; // 前一个
    }

    for (int i = 0; i < 5; ++i)
    {
        cout << sugar[i] << " ";
    }
    cout << endl
         << eat;
    return 0;
}
