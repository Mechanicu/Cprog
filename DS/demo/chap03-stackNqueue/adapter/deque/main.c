#include <stdio.h>

#include "deque.h"

#define EOL putchar('\n')

void print(ElemType *e)
{
    printf("%4d", *e);
}

int main()
{
    deque q, *Q = &q;
    ElemType e, v;

    deque_init(Q);

    for (int i = 1; i <= 20; i++)
        if (i % 2 == 0) deque_push_back(Q, i);
        else deque_push_front(Q, i);
    deque_insert(Q, 11, 0);
    deque_traverse(Q, print);
    EOL;

    for (int i = 1; i <= 8; i++)
        if (i % 2 == 0) deque_pop_back(Q);
        else deque_pop_front(Q);
    deque_erase(Q, 7);
    deque_traverse(Q, print);
    EOL;

    deque_front(Q, &e);
    deque_back(Q, &v);
    printf("front=%d, back=%d\n", e, v);
    
    return 0;
}