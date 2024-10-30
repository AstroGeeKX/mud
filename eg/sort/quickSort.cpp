#include <iostream>
#include <vector>

using namespace std;
void quickSort(vector<int> &arr, int left, int right){
    if(left >= right)
        return;
    int i = left, j = right;
    int pivot = arr[left];
    while(i < j){
        while(j > i && arr[j] >= pivot)
            j--;
        while(i < j && arr[i] <= pivot)
            i++;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[i]);
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main(){
    vector<int> arr = {10, 9, 8, 7, 6, 5, 2, 4, 3, 1};
    quickSort(arr, 0, arr.size() - 1);
    for(auto &each : arr)
        cout << each << " ";
    cout << endl;
    return 0;
}

