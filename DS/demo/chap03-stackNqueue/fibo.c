#include <stdio.h>

size_t fibo1(size_t n)
{
    return n <= 2 ? 1 : fibo1(n - 1) + fibo1(n - 2);
}

size_t fibo2(size_t n, size_t a, size_t b)
{
    return n <= 2 ? b : fibo2(n - 1, b, a + b);
}

size_t fibo3(size_t n)
{
    return fibo2(n, 1, 1);
}

size_t fibo4(size_t n)
{
    size_t a = 1, b = 1, t;

    for (size_t i = 3; i <= n; ++i)
    {
        t = b;
        b += a;
        a = t;
    }

    return b;
}

int main()
{
    size_t N = 10;

    printf("%lu\n", fibo1(N));
    printf("%lu\n", fibo2(N, 1, 1));
    printf("%lu\n", fibo3(N));
    printf("%lu\n", fibo4(N));

    return 0;
}