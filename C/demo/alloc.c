#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;

    q = p = (int *)malloc(sizeof(int));
    *p = 1;
    printf("%d\n", *p);

    free(p);

    //may cause fatal error
    *q = 2;

    return 0;
}