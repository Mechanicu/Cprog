#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int i;

    srand(time(NULL));

    for (i = 0; i < 10; ++i)
        if (argc < 2)
            printf("%d\n", rand() % 100);
        else
            printf("%d\t%d\n", rand() % 100, rand() % 100);

    return 0;
}