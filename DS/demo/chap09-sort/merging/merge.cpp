#include <cstdlib>
#include "../record.h"

static void Merge(RecordType r1[], RecordType r2[], int low, int mid, int high)
/* 已知r1[low..mid]和r1[mid+1..high]分别按关键字有序排列，将它们合并成一个有序序列，存放在r2[low..high] */
{
    int i = low, j = mid + 1, k = low;

    while ((i <= mid) && (j <= high))
    {
        if (r1[i].key <= r1[j].key)
        {
            r2[k] = r1[i];
            ++i;
        }
        else
        {
            r2[k] = r1[j];
            ++j;
        }
        ++k;
    }
    while (i <= mid)
    {
        r2[k] = r1[i];
        ++k;
        ++i;
    }
    while (j <= high)
    {
        r2[k] = r1[j];
        ++k;
        ++j;
    }
} /* Merge */

static int len;
static void _MergeSort_(RecordType src[], RecordType dest[], int low, int high)
/* src[low..high]经过排序后放在dest[low..high]中，aux[low..high]为辅助空间 */
{
    int mid;

    if (low == high)
    {
        dest[low] = src[low];
        return;
    }

    RecordType *aux = (RecordType *)malloc(sizeof(RecordType) * len);
    mid = (low + high) / 2;
    _MergeSort_(src, aux, low, mid);
    _MergeSort_(src, aux, mid + 1, high);
    Merge(aux, dest, low, mid, high);
    free(aux);
} /*   _MergeSort_  */

void MergeSort(RecordType r[], int n)
/* 对记录数组r[1..n]做归并排序 */
{
    len = n + 1;
    _MergeSort_(r, r, 1, n);
}
