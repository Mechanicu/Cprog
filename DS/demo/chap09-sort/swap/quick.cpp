#include "../record.h"

static int Pivot(RecordType r[], int low, int high)
/*对记录数组r 中的r[left]至r[right]部分进行一趟排序，并得到基准的位置，使得排序后的结果满足其之后（前）的记录的关键字均不小于（大于）于基准记录*/
{
    RecordType x = r[low]; /* 选择基准记录*/

    while (low < high)
    {
        while (low < high && r[high].key >= x.key) /* high从右到左找小于x.key的记录 */
            --high;
        if (low < high)
        {
            r[low] = r[high];
            ++low;
        }

        /* 找到小于x.key的记录，则进行交换*/
        while (low < high && r[low].key < x.key) /* low从左到右找大于x.key的记录 */
            ++low;
        if (low < high)
        {
            r[high] = r[low];
            --high;
        } /* 找到大于x.key的记录，则交换*/
    }

    r[low] = x; /*将基准记录保存到low=high的位置*/
    return low; /*返回基准记录的位置*/
} 

static void _QuickSort_(RecordType r[], int low, int high)
/*对记录数组r[low..high]用快速排序算法进行排序*/
{
    if (low < high)
    {
        int pivot = Pivot(r, low, high); /*调用一趟快速排序，将枢轴元素为界划分两个子表*/
        _QuickSort_(r, low, pivot - 1);	/*对左部子表快速排序*/
        _QuickSort_(r, pivot + 1, high);	/*对右部子表快速排序*/
    }
}

void QuickSort(RecordType r[], int length) // wrapper
{
    _QuickSort_(r, 1, length);
}