#include <stdio.h>

int main()
{
    int i;
    double sum = 0;
    int sign = 1;

    for (i = 1; i <= 100; ++i)
    {
        sum += sign * 1.0 / i;
        sign = -sign;
    }

    printf("%lf\n", sum);

    return 0;
}