#include <stdio.h>
#include <stdlib.h>
#include "include.h"
// GB2312

/* 
统计各种排序在面对相同的数组时所需的时间
默认数组为整型
默认（可改变）数组的大小N 
默认范围略大于N（防止元素过多重复带来的误差
对数组进行了从小到大和从大到小的排序
*/


void getTime(int n, int cmd) {
    int* arr = creatArr(n, cmd);

    printf("冒泡排序: ");
    timer(arr, n, 1, BubbleSort);

    printf("选择排序: ");
    timer(arr, n, 1, SelectionSort);

    printf("插入排序: ");
    timer(arr, n, 1, InsertionSort);

    printf("归并排序: ");
    timerM(arr, n, 1);

// 由于在最坏的情况（因为本题算法实现默认比较值在最左边）下快排在100000的时候，栈会溢出，所以快排不测量最坏时间
    if(cmd == 0) { 
        printf("快速排序: ");
        timerQ(arr, n, 1);
    }
}

void test104() {  // 10000

    printf("数据量达到1万\n");

    printf("随机排序比较:\n");
    getTime(10000, 0);

    printf("最好的情况（数组本身有序）\n");
    getTime(10000, 1);
    
    printf("最坏的情况（数组完全逆序）\n");
    getTime(10000, -1);


}




void test105() { //100000

    printf("数据量达到10万\n");

    printf("随机排序比较:\n");
    getTime(100000, 0);
    
    printf("最好的情况（数组本身有序）\n");
    getTime(100000, 1);
    
    printf("最坏的情况（数组完全逆序）\n");
    getTime(100000, -1);
}

// 其他算法时间太慢就不进行100万次的计算， 只对归并排序和快速排序进行测量
void test106() {
    printf("数据量达到100万");
    int* arr = creatArr(1000000, 1);
    printf("归并排序: ");
    timerM(arr, 1000000, 1);

}




int main(){

    test104();

    test105();

    test106();

    return 0;
}

