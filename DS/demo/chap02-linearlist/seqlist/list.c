#include "list.h"

void InitList(LListPtr *L)
{
    (*L)->last = -1;
}

bool InsList(LListPtr L, int i, ElemType e)
{
    if (i < 1 || i > L->last + 2) return false;

    for (int j = L->last; j >= i - 1; --j)
        L->elem[j + 1] = L->elem[j];
    L->elem[i - 1] = e;
    ++L->last;

    return true;
}

bool DelList(LListPtr L, int i, ElemType *e)
{
    if (i < 1 || i > L->last + 1)   
        return false;

    *e = L->elem[i-1];  /* 将删除的元素存放到e所指向的变量中*/
    for (int k = i; k <= L->last; ++k)
        L->elem[k-1] = L->elem[k];  /*将后面的元素依次前移*/
    --L->last;

    return true;
}

void traverse(LListPtr L, CALLBACK f)
{
    for (int i = 0; i <= L->last; ++i)
        f(&L->elem[i]);
}