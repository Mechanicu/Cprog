#pragma once

#include "../deque/deque.h"

//queue: adapter of linear-list
//using underlying container to access element
typedef struct 
{
    deque q; //underlying container is a deque object
} queue, *queueptr;

extern void queue_init(queueptr S);
extern void queue_push(queueptr S, ElemType e);
extern void queue_pop(queueptr S);
extern ElemType queue_front(queueptr S);
extern ElemType queue_back(queueptr S);
extern bool queue_empty(queueptr S);
extern bool queue_full(queueptr S);

extern void queue_traverse(queueptr S, CALLBACK f);