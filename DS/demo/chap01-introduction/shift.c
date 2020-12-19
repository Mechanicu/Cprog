#include <stdio.h>

#define N   9

void print(int x[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%4d", x[i]);
    printf("\n");
}

void shift(int x[], int n, int m)
{
    int t;

    while (m-- > 0)
    {
        t = x[0];
        for (int i = 1; i < n; ++i)
            x[i-1] = x[i];
        x[n-1] = t;
    }
}

int main()
{
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(a, N);

    shift(a, N, 6);

    print(a, N);

    return 0;
}