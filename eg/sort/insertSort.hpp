void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; // 将当前元素作为key
        j = i - 1;

        // 将大于key的元素向后移动一位
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // 将key插入到正确位置
    }
}

void myInsertSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; ++i)
    {
        key = arr[i];
        j = i - 1;
        // 截止条件 && 起始条件
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// 插入排序的过程有点类似顺序表一直向后移动
// 移动的过程的逻辑是很清晰简洁的
// 最外一层循环的遍历也是清晰的