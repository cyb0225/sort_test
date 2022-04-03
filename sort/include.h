#ifndef MY_INCLUDE
#define MY_INCLUDE

// function.c
//打印数组
void print(int* arr, int n);
//创建一个数组
int* creatArr(int n, int cmd); 
//拷贝生成同一份数据
int* copyArr(int* arr, int n);
//交换数组中的两个元素
void swap(int* a, int* b); 
//计时器
void timer(int* arr, int n, int k, void(*sort)(int*, int, int)); 
void timerQ(int* arr, int n, int k); // 快排专属计时器
void timerM(int* arr, int n, int k); // 归并排序计时器

// 排序算法

// 冒泡排序
void BubbleSort(int *arr, int n, int k);
// 选择排序
void SelectionSort(int* arr, int n, int k);
// 插入排序
void InsertionSort(int* arr, int n, int k);
// 归并排序
void MergeSort(int* arr, int low, int high, int* aux, int k);
// 快速排序
void QuickSort(int* arr, int low, int high, int k);

#endif
