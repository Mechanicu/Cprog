#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void print(ElemType *e)
{
    printf("%4d", *e);
}

int main()
{
    LList list, *L = &list;

    InitList(&L);
    
    for (int i = 1; i < 10; ++i)
        InsList(L, i, i + 10);

    traverse(L, print);
    printf("\n");

    return 0;
}