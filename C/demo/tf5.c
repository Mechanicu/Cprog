#include <stdio.h>

int main()
{
    int a[128] = {1, 2, 3, 4, 5, 6};
    int N = 6;
    int pos = 2;
    int i, key = 7;

    for (i = N; i >= pos; --i)
        a[i] = a[i - 1];
    a[i] = key;
    ++N;

    return 0;
}