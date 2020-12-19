#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    // int [5]
    int *p;
    // int *
    int i;

    //p = &a[0];
    // a === &a[0]
    // *(a+i) === a[i]
    // a+i === &a[i]
    p = a;
    // p[i] === a[i]
    // *(p+i) === *(a+i)
    // p+i === a+i
    // a[i] === *(a+i) === *(i+a) === i[a]

    // for (i = 0; i < 5; ++i)
    //     printf("%4d", a[i]);
    // putchar('\n');

    // for (p = a + 4; p > a; --p)
    //     *p = *(p - 1);
    //     //printf("%4d", *p);
    // *p = 0;
    for (p=&a[2], i = 0; i < 3; ++i)
        printf("%4d", p[i]);
    putchar('\n');

    return 0;
}
