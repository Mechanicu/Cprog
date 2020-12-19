#include <stdio.h>

int f()
{
    static int i = 0;
    ++i;
    return i;
}

int g()
{
    int i = 0;
    ++i;
    return i;
}

int main()
{
    printf("%d, %d\n", f(), g());
    f(); g();
    printf("%d, %d\n", f(), g());

    return 0;
}
