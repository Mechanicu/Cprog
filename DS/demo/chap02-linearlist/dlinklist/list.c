#include <stdio.h>
#include <malloc.h>

#include "list.h"
#include "list_interface.h"

void InitList(LListPtr *L)
{
    (*L) = (NodePtr)malloc(sizeof(Node)); //生成头结点
    (*L)->prior = (*L)->next = NULL; //头结点的指针域为空
}

//请根据教材自行完成下列函数的编码
bool InsList(LListPtr L, int i, ElemType e)
{
	NodePtr p = L, s;
	int k = 1;
    
    /*从"头"开始，查找第i-1个结点*/
	while (p != NULL && k < i)  /*表未查完且未查到第i-1个时重复，找到p指向第i-1个*/ 
	{ 
		p = p->next;
		++k; 
	}
    
	if (p == NULL && k < i)   /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return false;
	}

	s = (NodePtr)malloc(sizeof(Node));   /*申请一个新的结点S */
	s->data = e;                       /*值e置入s的数据域*/
	if (p->next == NULL) //p指向最后一个元素
	{
		p->next = s;
		s->next = NULL;
		s->prior = p;
	}
	else
	{
		p = p->next; //因为是在节点前插入，因此需要再前进一步

		s->prior = p->prior;
		p->prior->next = s;
		s->next = p;
		p->prior = s;
	}
	
    return true;
}

bool DelList(LListPtr L, int i, ElemType *e)
{
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