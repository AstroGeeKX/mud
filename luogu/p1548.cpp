#include <iostream>

int squares_num(int N,int M);
int rectangles_num(int N,int M);

int main()
{
    using namespace std;
    int N,M;
    cin >> N >> M;
    cout << squares_num(N,M) << " " << rectangles_num(N,M);
    return 0;
}

int squares_num(int N,int M)
{
    int num = 0;
    for (int i = 1; i <= N && i<= M; i++)
    {
        num += (N-i+1) * (M-i+1);
    }
    return num;
}

int rectangles_num(int N,int M)
{
    int num = 0;
    for (int a = 1; a <= N; a++)
    {
        for (int aa = 1; aa <= M; aa++)
        {
            if (aa == a)
                continue;
            num += (N-a+1) * (M-aa+1);
        }
    }
    return num;
}