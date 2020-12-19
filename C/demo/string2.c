#include <stdio.h>

size_t strlen(char *s)
{
    char *t = s;
    while (*t++);
    return t - s - 1;
}

char* strcpy(char *dest, const char *src)
{
    char *t = dest;
    while ((*t++ = *src++));
    return dest;
}

int * foo()
{
    static int i = 1;
    return &i;
}

int main()
{
    char *p = "1234567890";
    char *q, *t;
    char buf[1024];
    int *j;

    q = buf;
    printf("%ld\n", strlen(p));
    t = strcpy(q, p);
    *t = 'X';
    printf("%s\n", t);

    *foo() = 0;
    printf("%d\n", *foo());

    if ("abc" == "abc") ;
    strcmp(p, q);

    return 0;
}