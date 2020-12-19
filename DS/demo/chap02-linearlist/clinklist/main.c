#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "list_interface.h"

void print(ElemType *e)
{
    printf("%4d", *e);
}

ElemType reverse_i(LListPtr L, int i)
{
    NodePtr p, q;
    int k;

    for (k = 0, p = L; k < i; p = p->next, ++k);
    for (q = L; p != L; p = p->next, q = q->next);

    return q->data;
}

int main()
{
    LListPtr list;

    InitList(&list);
    
    for (int i = 1; i < 10; ++i)
        InsList(list, i, i + 10);

    traverse(list, print);
    printf("\n");

    printf("%d\n", reverse_i(list, 3));

    DestroyList(list);

    return 0;
}