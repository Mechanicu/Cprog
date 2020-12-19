#include <stdio.h>
#include <malloc.h>

#include "list.h"

void InitList(LListPtr *L)
{
    (*L) = (NodePtr)malloc(sizeof(Node)); //生成头结点
    (*L)->next = NULL; //头结点的指针域为空
}

bool InsList(LListPtr L, int i, ElemType e)
{
	NodePtr p = L, q;
	int k = 1;
    
	while (p != NULL && k < i)
	{ 
		p = p->next;
		++k; 
	}
    
	if (p == NULL && k < i)
	{ 
		printf("插入位置不合理!");
		return false;
	}

	q = (NodePtr)malloc(sizeof(Node));   /*申请一个新的结点S */
	q->data = e;                       /*值e置入s的数据域*/
	q->next = p->next;				/*修改指针，完成插入操作*/
	p->next = q;
	
    return true;
}

bool DelList(LListPtr L, int i, ElemType *e)
{
	NodePtr p = L, q;
	int k = 1;
    
	while (p != NULL && k < i)
	{ 
		p = p->next;
		++k; 
	}
    
	if (p == NULL && k < i)
	{ 
		printf("删除位置不合理!");
		return false;
	}

	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	
    return true;
}

void traverse(LListPtr L, CALLBACK f)
{
    NodePtr p = L->next;
	while (p != NULL)
	{
        f(&p->data);
        p = p->next;
	}
}

void DestroyList(LListPtr L)
{
    NodePtr p = L, q;
	while (p != NULL)
	{
        q = p;
		p = p->next;
		free(q);
	}
}