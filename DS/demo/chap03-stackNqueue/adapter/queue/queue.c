#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void queue_init(queueptr S)
{
    deque_init(&S->q);
}

void queue_push(queueptr S, ElemType e)
{
    if (!queue_full(S)) 
        deque_push_back(&S->q, e);
    else
    {
        printf("queue overflow!\n");
        exit(-1);
    }
}

void queue_pop(queueptr S)
{
    if (!queue_empty(S))
        deque_pop_front(&S->q);
    else
    {
        printf("queue underflow!\n");
        exit(-2);
    }
}

ElemType queue_front(queueptr S)
{
    ElemType e;
    deque_front(&S->q, &e);
    return e;
}

ElemType queue_back(queueptr S)
{
    ElemType e;
    deque_back(&S->q, &e);
    return e;
}

bool queue_empty(queueptr S)
{
    return deque_empty(&S->q);
}

bool queue_full(queueptr S)
{
    return deque_full(&S->q);
}

void queue_traverse(queueptr S, CALLBACK f)
{
    deque_traverse(&S->q, f);
}