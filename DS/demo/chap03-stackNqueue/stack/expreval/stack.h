#pragma once

#include <stdbool.h>

#include "stack_elemtype.h"

typedef struct node
{
	StackElementType data;
	struct node *next;
} Node, *NodePtr, Stack, *StackPtr;

extern void InitStack(StackPtr S);
extern bool Push(StackPtr S, StackElementType x);
extern bool Pop(StackPtr S, StackElementType* x);
extern bool GetTop(StackPtr S, StackElementType* x);
extern void ClearStack(StackPtr S);
extern bool IsEmpty(StackPtr S);
extern bool IsFull(StackPtr S);