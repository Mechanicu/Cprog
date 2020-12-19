#include <stdio.h>

unsigned long fact(unsigned long n)
{
    return n <= 1 ? 1 : fact(n - 1) * n;

    // unsigned long f = 1;
    // for (unsigned long i = 1; i <= n; ++i)
    //     f *= i;
    // return f;

    // fact(6) => return fact(5) * 6; => return 120 * 6;
    // fact(5) => return fact(4) * 5; => return 24 * 5;
    // fact(4) => return fact(3) * 4; => return 6 * 4;
    // fact(3) => return fact(2) * 3; => return 2 * 3;
    // fact(2) => return fact(1) * 2; => return 1 * 2;
    // fact(1) => return 1;
} 

int main()
{
    unsigned long n;

    scanf("%ld", &n);
    printf("%ld\n", fact(n));

    return 0;
}