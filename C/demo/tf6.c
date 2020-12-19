#include <stdio.h>

void decomp(double x, int *i, double *f)
{
    *i = (int)x;
    *f = x - *i;
}

int main()
{
    double a = 3.1415;
    int i;
    double f;

    decomp(a, &i, &f);

    return 0;
}