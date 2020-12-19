#pragma once

#include "../deque/deque.h"

//stack: adapter of linear-list
//using underlying container to access element
typedef struct 
{
    deque q; //underlying container is a deque object
} stack, *stackptr;

extern void stack_init(stackptr S);
extern void stack_push(stackptr S, ElemType e);
extern void stack_pop(stackptr S);
extern ElemType stack_top(stackptr S);
extern bool stack_empty(stackptr S);
extern bool stack_full(stackptr S);

extern void stack_walk(stackptr S, CALLBACK f);