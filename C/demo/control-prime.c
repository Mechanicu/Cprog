#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n, r, i;
    bool isPrime = true;

    scanf("%d", &n);
    for (i = 2; i <= sqrt(n); ++i)
    {
        r = n % i;
        if (r == 0)
        {
            isPrime = false;
            break;
        }
    }
    printf(isPrime ? "yes" : "no");

    return 0;
}