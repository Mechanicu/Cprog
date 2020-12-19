#include <stdio.h>
#include <string.h>

void bubble_sort(char *a[], int len)
{
    int i, j;
    //char t[8];

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (strcmp(a[j], a[j+1]) > 0)
            { // block
                char *t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

int main()
{
    char * planet[8] = {
        "Mecurry",
        "Venus",
        "Earth",
        "Mars",
        "Jupiter",
        "Saturn",
        "Neptune",
        "Urinas"
    };
    int i;

    bubble_sort(planet, 8);

    for (i = 0; i < 8; ++i)
        printf("%s\n", planet[i]);

    return 0;
}
