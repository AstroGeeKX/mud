template <typename T>
int Paritition(T A[], int low, int high) {
  int pivot = A[low];
  while (low < high) {
    while (low < high && pivot <= A[high]) --high;
    A[low] = A[high];
    while (low < high && A[low] <= pivot) ++low;
    A[high] = A[low];
  }
  A[low] = pivot;
  return low;
}

template <typename T>
void QuickSort(T A[], int low, int high) {
  if (low < high) {
    int pivot = Paritition(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot + 1, high);
  }
}

template <typename T> // 简化参数的封装函数
void QuickSort(T A[], int len) {
  QuickSort(A, 0, len - 1);
}

// 这里是wiki oi的快排示例