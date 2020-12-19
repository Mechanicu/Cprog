#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

#include "stack.h"

void InitStack(StackPtr S)
{
    S->next = NULL;
}

bool Push(StackPtr S, StackElementType x)
{
	NodePtr t;

	t = (NodePtr)malloc(sizeof(Node));
 	if (t == NULL)  //申请空间失败
 		return false;

	t->data = x;
	t->next = S->next;
	S->next = t;

	return true;
}

bool Pop(StackPtr S, StackElementType* x)
{
	/* 将栈top的栈顶元素弹出，放到x所指的存储空间中 */
	NodePtr t;

	if (IsEmpty(S))
		return false;

	t = S->next;
	S->next = t->next;
	*x = t->data;
	free(t);

	return true;
}

bool GetTop(StackPtr S, StackElementType* x)
{
	if (IsEmpty(S))
		return false;

	*x = S->next->data;
	return true;	
}

void ClearStack(StackPtr S)
{
    NodePtr p = S->next, q;
	while (p != NULL)
	{
        q = p;
		p = p->next;
		free(q);
	}
}

bool IsEmpty(StackPtr S)
{
    return S->next == NULL;
}

bool IsFull(StackPtr S)
{
    return false;
}