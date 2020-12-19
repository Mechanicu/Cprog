#include "../record.h"

void BinSort(RecordType r[], int length)
/*对记录数组r进行折半插入排序，length为数组的长度*/
{
    int i, j;
    int low, high, mid;

    for (i = 2; i <= length; ++i)
    {
        r[0] = r[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (r[0].key < r[mid].key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= low; --j)
            r[j + 1] = r[j];
        r[low] = r[0];
    }
} /*BinSort*/