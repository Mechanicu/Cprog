#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

const char *file = "test.data";

typedef uint16_t KeyType;

int main(int argc, char *argv[])
{
    FILE *fp;
    KeyType len, d;
    int size = sizeof(KeyType);
    const KeyType limit = 65535u;

    if (argc < 2)
    {
        printf("Usage: gen_data <number of data>\n");
        exit(0);
    }

    len = atoi(argv[1]);
    if (len > 20480)
    {
        printf("The number of data(%d) is too large, please choose one less than 20480\n", len);
        exit(0);
    }

    srand(time(NULL));

    fp = fopen(file, "wb");
    fwrite(&len, size, 1, fp);
    for (int i = 0; i < len; ++i)
    {
        d = rand() % limit;
        fwrite(&d, size, 1, fp);
    }
    fclose(fp);

    printf("All data was written into file test.data\n"
    "*** Note: the value of the first 2 bytes is the count of data\n");

    return 0;
}