#include "../record.h"

void SelectSort(RecordType r[], int length)
/*对记录数组r做简单选择排序，length为数组的长度*/
{
    int k, j, i;
    RecordType x;

    for (i = 1; i < length; ++i)
    {
        k = i;
        for (j = i + 1; j <= length; ++j)
            if (r[j].key < r[k].key)
                k = j;

        if (k != i)
        {
            x = r[i];
            r[i] = r[k];
            r[k] = x;
        }
    }
} /* SelectSort  */
