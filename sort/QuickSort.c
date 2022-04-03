#include "include.h"

/*
    快速排序
    采用分治思想， 先取数组中的一个数，将小于/大于他的数分别放到两边， 然后递归操作， 直到分数组个数为1
    QuickSort 函数是对递归分治思想的体现， 而QuickPass 函数是中间算法的实现。
*/
int QuickPass(int* arr, int low, int high, int k);

void QuickSort(int* arr, int low, int high, int k) { // 左闭右闭[low, high]
    if(low >= high) { // 数组大小为1 就不用排序操作了
        return;
    }

    int pivot = QuickPass(arr, low, high, k); //中间结点的下标

    QuickSort(arr, low, pivot - 1, k);
    QuickSort(arr, pivot + 1, high, k);

}
/*
    核心思想是通过取出左边的数，将右边的数放到左边空闲的位置，
    然后对左边的数遍历将左边的数放到右边刚刚空出来的位置
*/


// 快速划分 返回枢纽元素所在位置
int QuickPass(int* arr, int low, int high, int k) {
    // 这里默认取low为枢纽元素的下标, 最后返回改变后的low
    int x = arr[low]; // 此时下标为low的地址是“空”的 下一个high的元素放到该位置

    while(low < high) {

        // 找出右边第一个比low小的元素的下标
        while(low < high && x * k <= arr[high] * k) { 
            --high;
        }

        if(low == high) break; // 表示右边的元素都比x大

        arr[low++] = arr[high]; // 此时 high 的位置空出来了
        
        while(low < high && arr[low] * k <= x * k) {
            ++low;
        }

        if(low == high) break;

        arr[high--] = arr[low];
    }

    // 最后将中枢元素归位
    arr[low] = x;
    
    return low;
}
