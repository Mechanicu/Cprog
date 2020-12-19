#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

void deque_init(dequeptr Q)
{
    Q->last = -1;
}

bool deque_insert(dequeptr Q, int i, ElemType e)
{
    if (i < 1 || i > Q->last + 2 || deque_full(Q))
        return false;

    for (int j = Q->last; j >= i - 1; --j)
        Q->elem[j + 1] = Q->elem[j];
    Q->elem[i - 1] = e;
    ++Q->last;

    return true;
}

bool deque_erase(dequeptr Q, int i)
{
    if (i < 1 || i > Q->last + 1 || deque_empty(Q))   
        return false;

    for (int k = i; k <= Q->last; ++k)
        Q->elem[k-1] = Q->elem[k];
    --Q->last;

    return true;
}

bool deque_push_front(dequeptr Q, ElemType e)
{
    return deque_insert(Q, 1, e);
}

bool deque_push_back(dequeptr Q, ElemType e)
{
    return deque_insert(Q, Q->last + 2, e);
}

void deque_pop_front(dequeptr Q)
{
    deque_erase(Q, 1);
}

void deque_pop_back(dequeptr Q)
{
    deque_erase(Q, Q->last + 1);
}

bool deque_front(dequeptr Q, ElemType *e)
{
    if (deque_empty(Q)) 
        return false;

    *e = Q->elem[0];
    return true;
}

bool deque_back(dequeptr Q, ElemType *e)
{
    if (deque_empty(Q))
        return false;

    *e = Q->elem[Q->last];
    return true;
}

bool deque_empty(dequeptr Q)
{
    return Q->last == -1;
}

bool deque_full(dequeptr Q)
{
    return Q->last == MAXSIZE - 1;
}

void deque_traverse(dequeptr Q, CALLBACK f)
{
    for (int i = 0; i <= Q->last; ++i)
        f(&Q->elem[i]);
}