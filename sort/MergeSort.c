#include "include.h"
// #include <stdio.h>

/*  
    分治排序

    通过分治思想对数组进行对半拆分， 再自底向上进行排序合并。
*/
void Merge(int* arr, int low, int high, int mid, int* aux, int k);

// 排序调用的函数 主函数
void MergeSort(int* arr, int low, int high, int* aux, int k) { // 需要额外空间O(n) aux
    // printf("%d %d\n", low, high);
    if(low >= high) return; // [low, high] 表示需要sort的范围

    int mid = (high - low) / 2 + low; // 对半分 
    // 递归的思想 （范围采取左闭右闭）
    MergeSort(arr, low, mid, aux, k);
    MergeSort(arr, mid + 1, high, aux, k);

    // 前面MergeSort可以保证左右两个数组分别有序
    Merge(arr, low, high, mid, aux, k);
    
    for(int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}


// aux 主要作为存储排序后数组的缓冲区
void Merge(int* arr, int low, int high, int mid, int* aux, int k) {
    // 将两段数据比大小然后插入到aux中
    int i = low, j = mid + 1;
    int t = i; // aux的下标

    while(i <= mid && j <= high) {
        if(arr[i] * k < arr[j] * k) {
            aux[t++] = arr[i++];
        }
        else {
            aux[t++] = arr[j++];
        }
    }

    // 可能存在有数组还有没排进去的情况
    while(i <= mid) {
        aux[t++] = arr[i++];
    }
    
    while(j <= high) {
        aux[t++] = arr[j++];
    }
}