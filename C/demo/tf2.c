#include <stdio.h>

int f(int a)
{
    static int x = 0;
    return ++x * a;
}

int main()
{
    int i;

    for (i = 4; i > 0; --i)
        printf("%d\n", f(i));

    return 0;
}