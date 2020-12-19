#include <cstdlib>
#include "../record.h"

static void Merge(RecordType r[], int low, int mid, int high)
/* 已知r[low..mid]和r[mid+1..high]分别按关键字有序排列，将它们合并成一个有序序列，存放在r[low..high] */
{
    int i = low, j = mid + 1, k = 0;
    int len = high - low + 1;
    RecordType *aux = (RecordType *)malloc(sizeof(RecordType) * len);

    while ((i <= mid) && (j <= high))
        aux[k++] = r[r[i].key <= r[j].key ? i++ : j++];

    while (i <= mid)
        aux[k++] = r[i++];

    while (j <= high)
        aux[k++] = r[j++];

    for (i = 0; i < len; ++i)
        r[low + i] = aux[i];

    free(aux);
} /* Merge */

static void _MergeSort_(RecordType r[], int low, int high)
{
    if (low == high)
        return;

    int mid = (low + high) / 2;
    _MergeSort_(r, low, mid);
    _MergeSort_(r, mid + 1, high);
    Merge(r, low, mid, high);
} /*   _MergeSort_  */

void MergeSort2(RecordType r[], int n)
/* 对记录数组r[1..n]做归并排序 */
{
    _MergeSort_(r, 1, n);
}
