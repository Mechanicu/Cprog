#pragma once

#include <stdbool.h>

#include "elemtype.h"

#define	MAXSIZE  1024

//Double-Ended QUEue -> deque, pronouced like 'deck'
typedef  struct
{ 
	ElemType  elem[MAXSIZE];
	int       last;
} deque, *dequeptr;

//prototype
extern void deque_init(dequeptr Q);
extern bool deque_insert(dequeptr Q, int i, ElemType e);
extern bool deque_erase(dequeptr Q, int i);
extern bool deque_push_front(dequeptr Q, ElemType e);
extern bool deque_push_back(dequeptr Q, ElemType e);
extern void deque_pop_front(dequeptr Q);
extern void deque_pop_back(dequeptr Q);
extern bool deque_front(dequeptr Q, ElemType *e);
extern bool deque_back(dequeptr Q, ElemType *e);
extern bool deque_empty(dequeptr Q);
extern bool deque_full(dequeptr Q);

typedef void (*CALLBACK)(ElemType*);
//typedef void CALLBACK(ElemType*);

extern void deque_traverse(dequeptr Q, CALLBACK f);