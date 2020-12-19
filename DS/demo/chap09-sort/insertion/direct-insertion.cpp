#include "../record.h"

void InsSort(RecordType r[], int length)
/* 对记录数组r做直接插入排序，length为数组中待排序记录的数目*/
{
    int i, j;

    for (i = 2; i <= length; ++i)
    {
        r[0] = r[i];
        j = i - 1;
        while (r[0].key < r[j].key)
        {
            r[j + 1] = r[j];
            --j;
        }
        r[j + 1] = r[0];
    }
} /*  InsSort  */