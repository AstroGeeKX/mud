#include <iostream>
#include <cstdlib>
#include <chrono>
#include "quickSort_T.hpp"
#include "merge_sort.hpp"
#include "insertSort.hpp"
#include "shellSort.hpp"

#define START auto start = std::chrono::high_resolution_clock::now()
#define END auto end = std::chrono::high_resolution_clock::now()
#define DURATION auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

void printArray(int arr[], int len)
{
    for (int i = 1; i <= len; i++)
    {
        std::cout << arr[i - 1] << " ";
        if (i % 10 == 0 && i != 0)
            std::cout << std::endl; 
    }
}

#define arraySIZE 100000 // 517779几乎是最大数字

int main()
{
    int array[arraySIZE]{};
    int arrTemp[arraySIZE]{};
    
    std::srand(std::time(0));
    for (int i = 0; i < arraySIZE; ++i) { array[i] = (std::rand() % 10001); }

    START;
    // MergeSort(array, arrTemp, 0, arraySIZE);
    // insertionSort(array, arraySIZE);
    // shellSort(array, arraySIZE);
    QuickSort<int>(array, arraySIZE);
    END;

    // printArray(array, 500);

    DURATION;
    std::cout << arraySIZE << " size ";
    std::cout << "execution time: " << duration / 1000 << " ms" << std::endl;
   
    return 0;
}
