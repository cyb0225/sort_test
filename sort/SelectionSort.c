#include "include.h"

// 简单选择排序
void SelectionSort(int* arr, int n, int k) {

    for(int i = 0; i < n - 1; i++) { // 控制循环遍数

        int tmpI = i; // 假设当前最小(最大)值在 i 位置
    
        for (int j = i + 1; j < n; j++) {
            if(arr[j] * k < arr[tmpI] * k) {
                tmpI = j;
            }
        }
        if(tmpI != i) swap(&arr[tmpI], &arr[i]);
    }
    
}