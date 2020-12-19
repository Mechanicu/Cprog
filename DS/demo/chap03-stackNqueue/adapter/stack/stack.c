#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void stack_init(stackptr S)
{
    deque_init(&S->q);
}

void stack_push(stackptr S, ElemType e)
{
    if (!stack_full(S)) 
        deque_push_back(&S->q, e);
    else
    {
        printf("Stack overflow!\n");
        exit(-1);
    }
}

void stack_pop(stackptr S)
{
    if (!stack_empty(S))
        deque_pop_back(&S->q);
    else
    {
        printf("Stack underflow!\n");
        exit(-2);
    }
}

ElemType stack_top(stackptr S)
{
    ElemType e;
    deque_back(&S->q, &e);
    return e;
}

bool stack_empty(stackptr S)
{
    return deque_empty(&S->q);
}

bool stack_full(stackptr S)
{
    return deque_full(&S->q);
}

void stack_walk(stackptr S, CALLBACK f)
{
    deque_traverse(&S->q, f);
}