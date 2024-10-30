#include <cstdio>

void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex){
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1) { // 一直合并直到消耗完一个数组
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)  // 哪个数组还有剩余，就直接全部并入
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i]; // 结果存在临时变量里，逐一赋值到源数组中
}
 
//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex) {
    int midIndex;
    if(startIndex < endIndex) {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}
 
// 2 5 4 6 3
// 2 5 4  6 3
// 关键点：
// 深度优先原则：意味着在处理一组数据前，其下一级的所有数据已经完全处理完毕。
// 栈的利用：递归调用自动创建栈空间，记录每一次的调用状态，确保回溯时能按照正确的顺序进行合并。

// int main(int argc, char * argv[]) {
//     int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
//     int i, b[8];
//     MergeSort(a, b, 0, 7);
//     for(i=0; i<8; i++)
//         printf("%d ", a[i]);
//     printf("\n");
//     return 0;
// }