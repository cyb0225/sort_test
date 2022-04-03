#include "include.h"

// 冒泡排序 (未优化的)
void BubbleSort(int* arr, int n, int k) { // k 为 1 从小到大排序， k 为 0 从大到小排序  
    for(int i = 0; i < n - 1; i++) { //排序只需n-1次

        for(int j = 0; j < n - 1 - i; j++) { // 从小到大 最后面的已经排完了
    
            if(arr[j] * k > arr[j+1] * k) { 
                swap(&arr[j], &arr[j+1]);
            }
    
        }
    }
}
