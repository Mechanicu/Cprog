#include <stdio.h>
#include <stdbool.h>

int main()
{
    #define N   10

    int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key;
    int low, high, mid;
    bool found = false;

    printf("Please input an integer:");
    scanf("%d", &key);

    low = 0;
    high = N - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key) { found = true; break; }
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if (found)
        printf("%d was found at index %d.\n", key, mid);
    else
        printf("%d was not found in the array.\n", key);

    return 0;
}