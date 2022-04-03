#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include.h"

// 交换数组中的两个元素
void swap(int* a, int* b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
}


// 打印数组
void print(int* arr, int n) {

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

// 产生数组
int* creatArr(int n, int cmd) { // cmd用于选择顺序排列还是逆序排列还是随机
    
    int* arr = (int*)malloc(sizeof(int) * n);
    
    if(arr == NULL) {
        printf("creatSqArr error!\n");
        exit(0);
    }
    srand((unsigned)time(NULL));
    // 随机
    if(cmd == 0) {
        for(int i = 0; i < n; i++) {
            arr[i] = rand() % (2*n) + 1; // [1, 2*N]
        }
    }

    // 正序
    else if(cmd == 1) {
        for(int i = 0; i < n; i++) {
            arr[i] = i + 1;  // [1, N]
        }
    }

    // 逆序
    else if(cmd == -1) {
        for(int i = 0; i < n; i++) {
            arr[i] = n - i; // [N, 1]
        }

    }

    else {
        printf("cmd input error!\n");
        
    }
    return arr;
}

// 拷贝数组， 深拷贝
int* copyArr(int* arr, int n) {

    int* arr1 = (int*)malloc(sizeof(int) * n);
    if(arr1 == NULL) {
        printf("copyArr error\n");
        exit(0);
    }
    for(int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }

    return arr1;
}


//void InsertionSort(int* arr, int n, int k);

//计算函数排序所需时间
void timer(int* arr, int n, int k, void(*sort)(int*, int, int)){ 
    int* arr1 = copyArr(arr, n); //生成一个新的用于排序的数组
    clock_t start = clock();
    // print(arr, n);
    sort(arr1, n, k);
    // print(arr, n);
    // sort(arr, n, -k);
    // print(arr, n);
    clock_t end = clock();
    printf("%ldms\n", end - start);
    free(arr1);
}  

// 针对快排的计时器 
void timerQ(int* arr, int n, int k) {
    int* arr1 = copyArr(arr, n); //生成一个新的用于排序的数组
    clock_t start = clock();

    QuickSort(arr1, 0, n - 1, k);

    clock_t end = clock();
    printf("%ldms\n", end - start);
    free(arr1);
}

// 针对归并排序的计时器
void timerM(int* arr, int n, int k) {
    int* arr1 = copyArr(arr, n);
    clock_t start = clock();

    int* aux = malloc(sizeof(int) * n);
    if(aux == NULL) {
        printf("aux creat error\n");
        exit(0);
    }

    MergeSort(arr1, 0, n-1, aux, k);

    clock_t end = clock();

    printf("%ldms\n", end - start);
    free(arr1);
    free(aux);
}