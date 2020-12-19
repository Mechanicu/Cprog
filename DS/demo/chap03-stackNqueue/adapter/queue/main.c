#include <stdio.h>

#include "queue.h"

void print(ElemType *v)
{
    printf("%4d", *v);
}

int main()
{
    queue q, *Q = &q;

    queue_init(Q);

    ElemType c;
    for (c = 1; c <= 20; ++c)
        queue_push(Q, c);
    queue_traverse(Q, print);

    for (int i = 0; i < 10; ++i)
    {
        c = queue_front(Q);
        queue_pop(Q);
    }

    printf("\nThe last popped: %d\n", c);
    queue_traverse(Q, print);
    putchar('\n');

    return 0;
}