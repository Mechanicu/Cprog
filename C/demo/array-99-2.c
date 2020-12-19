#include <stdio.h>
#include <stdbool.h>

int main()
{
    #define N   9

    int a[N][N];
    int i, j;

    for (i = 1; i <= N; ++i)
        for (j = 1; j <= N; ++j)
            a[i - 1][j - 1] = i * j;
    
    for (i = 0; i < N; ++i)
    {
        printf("%*c", (i + 1) * 6, ' ');
        for (j = i; j < N; ++j)
            printf("%6d", a[i][j]);
        putchar('\n');
    }

    return 0;
}