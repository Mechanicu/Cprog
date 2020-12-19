#include <stdio.h>

int main()
{
    const char *s = "abc\ner";
    int i[] = {2, 4, 3, 1, 0, 5};
    int j;

    for (j = 0; j < 6; ++j)
        printf("%c", s[i[j]]);

    return 0;
}