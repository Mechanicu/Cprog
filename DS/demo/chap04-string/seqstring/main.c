#include <stdio.h>

#include "string.h"

int main()
{
    String s, t;

    StrSet(&s, "Hello, world! world!");
    StrSet(&t, "world");

    StrPrint(&s);
    putchar('\n');

    StrPrint(&t);
    putchar('\n');

    //StrCopy(&s, &t);
    // StrInsert(&s, 6, &t);
    // StrPrint(&s);
    // putchar('\n');

    int pos = 0;
    while (pos != -1)
    {
        pos = StrIndex(&s, pos+1, &t);
        printf("%d\n", pos);
    }

    return 0;
}