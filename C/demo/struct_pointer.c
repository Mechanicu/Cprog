#include <stdio.h>

typedef struct 
{
    int a;
    char c;
    char *s; //pointer as member
} foo, *fooPTR;

void boo(foo y)
{
    y.a = 2;
    y.c = 'B';
    y.s = "bamboo";
}

void goo(fooPTR y)
{
    y->a = 2;
    y->c = 'B';
    y->s = "google";
}

int main()
{
    foo x = {1, 'A', "football"};
    fooPTR p = &x;

    boo(x);
    printf("%d,%c,%s\n", x.a, x.c, x.s);

    goo(&x);
    printf("%d,%c,%s\n", x.a, x.c, x.s);

    return 0;
}