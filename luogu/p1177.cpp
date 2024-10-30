// P1177 【模板】排序

#include <iostream>
#include <cstdlib>

using namespace std;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 一个冒泡排序
void my_sort(int *p, int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
        
    }
    
}

int main()
{
    int n; // 数字个数
    cin >> n;
    int *array = (int*)malloc(sizeof(int) * n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    
    // 使用qsort排序数组
    qsort(array, n, sizeof(int), compare);
    for (size_t i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    
    return 0;
}

// array对用户来说是合法标识符