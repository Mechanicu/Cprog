#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define pi  3.1415926

//#define true    1

int main()
{
    double x, sin, sin_old, f, y;
    int i, sign;
    unsigned counter = 0;
    //const double pi = 3.1415926;

    x = 30.0 * pi / 180.0;
    sin = 0.0;
    i = 1;
    f = 1;
    y = x;
    sign = 1;
    sin_old = 2.0;

    do {
        ++counter;
        sin += sign * y / f;
        sign *= -1;
        y *= x * x;
        f *= (i + 1) * (i + 2);
        i += 2;
        if (fabs(sin_old - sin) < 1E-6) break;
        sin_old = sin;
    } while (true);

    counter = 0;
    --counter;
    printf("%lf, %u\n", sin, counter);

    return 0;
}