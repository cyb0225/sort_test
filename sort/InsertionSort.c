#include "include.h"

// 插入排序（未使用二分查找优化的版本）
void InsertionSort(int* arr, int n, int k) { 
    
    for(int i = 1; i < n; i++) {
        int x = arr[i];// 待插入的元素
        int j = i - 1; // 从后往前找插入， 可以保证后面元素在找插入位置的时候前面的元素是有序的。
        while(j >= 0 && x * k < arr[j] * k) {
            arr[j + 1] = arr[j];
            --j; 
        }
        arr[j + 1] = x;
    }
}