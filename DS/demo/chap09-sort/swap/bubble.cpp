#include "../record.h"

void BubbleSort(RecordType r[], int length)
/*对记录数组r做冒泡排序，length为数组的长度*/
{
    int i, j;
    RecordType x;
    bool swapped = true;

    for (i = 1; i <= length - 1 && swapped; ++i)
    {
        swapped = false;
        for (j = 1; j <= length - i; ++j)
            if (r[j+1].key < r[j].key)
            {
                x = r[j];
                r[j] = r[j+1];
                r[j+1] = x;
                swapped = true;
            }
    }
} /*  BubbleSort  */