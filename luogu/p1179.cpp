#include <cstdio>

int main()
{
    int l, r;
    int sum = 0;
    scanf("%d %d", &l, &r);
    // 填充数字到数组中
    for (; l <= r; l++)
    {
        int i = l;
        while (i > 10)
        {
            if (i % 10 == 2)
                sum++;
            i /= 10;
        }
        i == 2 ? sum++ : sum;
    }
    printf("%d", sum);
    return 0;
}