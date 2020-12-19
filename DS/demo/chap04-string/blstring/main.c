#include <stdio.h>

#include "string.h"

#define EOL putchar('\n')

int main()
{
    String s;

    StrSet(&s, "the quick fox jumps over a lazy dog");
    StrPrint(&s);
    putchar('\n');
    StrDestroy(&s);

    return 0;
}