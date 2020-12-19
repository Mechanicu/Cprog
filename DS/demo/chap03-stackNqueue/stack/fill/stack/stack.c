#include "stack.h"

////algo 3.1
void InitStack(StackPtr S)
{
    S->next = NULL;
}

//algo 3.8
bool Push(StackPtr top, StackElementType x)
{
	LinkStackNode *temp;
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
 	if(temp==NULL)  
 		return false;   /* 申请空间失败 */
	temp->data=x;
	temp->next=top->next;
	top->next=temp;   /* 修改当前栈顶指针 */ 
	return true;
}

//algo 3.9
bool Pop(StackPtr top, StackElementType* x)
{
	/* 将栈top的栈顶元素弹出，放到x所指的存储空间中 */
	LinkStackNode * temp;
	temp=top->next;
	if(temp==NULL)  /*栈为空*/
		return false;
	top->next=temp->next;
	*x=temp->data;
	free(temp);   /* 释放存储空间 */
	return true;
}

////algo 3.4
bool GetTop(StackPtr S, StackElementType* x)
{
	/* 将栈S的栈顶元素弹出，放到x所指的存储空间中，但栈顶指针保持不变 */
	if (IsEmpty(S))  /*栈为空*/
		return false;
	else
	{
		*x = S->next->data;
		return true;
	}	
}

void ClearStack(StackPtr S)
{
    LinkStackNode *p = S->next, *q;
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
