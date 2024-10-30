#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include "quickSort_T.hpp"
#include "merge_sort.hpp"

/*
    虽然数组和vector模板都可以用[]方块号访问，但是这两者的变量类型是不一样的
    数组就是通常的int，vector的类型是std::vector<int>的类型
*/

// 若要使用类(class)或结构体(struct)时必须重载大于(>)运算符
template <typename T>
void bubble_sort(T *arr, int len)
{
    T i, j, temp;
    for (i = 0; i < len - 1; i++)         // 最后一个元素不用排序，n-1个都排序好了，最后1个也必须是顺序的
        for (j = 0; j < len - 1 - i; j++) // 第a个数字，剩下遍历的数字就是n - a个
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void quickSort(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int i = left, j = right;
    int pivot = arr[left];
    while (i < j)
    {
        while (j > i && arr[j] >= pivot)
            j--;
        while (i < j && arr[i] <= pivot)
            i++;
        if (i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[left], arr[i]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

void myQuickSort(int array[], int left, int right)
{
    if (left >= right)
        return;
    int low = left, high = right; // 很简单地创建临时变量，左右下标
    int pivot = array[left]; // 选择首个元素作为中轴
    while (low < high)
    {
        while (low < high && array[low] <= pivot)
            ++low;
        while (low < high && array[high] >= pivot)
            --high;
        if (low < high) // 这行不加的话就会重复交换中值（多少个递归就重复多少次）
            std::swap(array[low], array[high]);
    }
    std::swap(array[left], array[low]); // 此时此刻low等于high等于中位数下标
    myQuickSort(array, left, low - 1);
    myQuickSort(array, low + 1, right);
}

#define arraySIZE 100000 // 用宏定义来给定数组初始化大小 517779几乎是最大数字

int main()
{
    int array[arraySIZE]{};
    int arrTemp[arraySIZE]{};
    // std::vector<int> array(arraySIZE);

    // Seed the random number generator 随机数种子，不是时间
    std::srand(std::time(0));
    for (int i = 0; i < arraySIZE; i++) { array[i] = (std::rand() % 10001); }

    // 第一个当前时刻
    auto start = std::chrono::high_resolution_clock::now();
    // bubble_sort<int>(array, arraySIZE);
    // quickSort(array, 0, arraySIZE);
    // QuickSort(array, 0, arraySIZE);
    MergeSort(array, arrTemp, 0, arraySIZE);
    auto end = std::chrono::high_resolution_clock::now();
    // 第二个当前时刻
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << arraySIZE << " 别人的算法 ";
    std::cout << "Execution time: " << duration / 1000 << " ms" << std::endl;
    // 排序的数组时间复杂度会上升 从6ms到287ms

    // auto my_start = std::chrono::high_resolution_clock::now();
    // myQuickSort(array, 0, arraySIZE);
    // auto my_end = std::chrono::high_resolution_clock::now();
    // auto my_duration = std::chrono::duration_cast<std::chrono::microseconds>(my_end - my_start).count();
    // std::cout << arraySIZE << " 我的算法 ";
    // std::cout << "Execution time: " << my_duration / 1000 << " ms" << std::endl;
    return 0;
}

// vector和数组的写入速度
// vector和数组的排序速度

template <typename T>
void printArray(T arr[], int len)
{
    // Print the array
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
        if (i % 10 == 0 && i != 0)
            std::cout << std::endl; // Print 10 numbers per line
    }
}