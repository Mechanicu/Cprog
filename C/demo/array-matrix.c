#include <stdio.h>

int main()
{
    #define M   3
    #define N   4
    #define K   2

    int a[M][N] = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {3, 4, 5, 6}
    },
    b[N][K] = {
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 4}
    },
    c[M][K] = {0};

    int i, j, k;

    for (i = 0; i < M; ++i)
        for (j = 0; j < K; ++j)
            for (k = 0; k < N; ++k)
                c[i][j] += a[i][k] * b[k][j];

    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < K; ++j)
            printf("%6d", c[i][j]);
        putchar('\n');
    }

    return 0;
}