#include <stdio.h>
#include <malloc.h>

#include "list.h"
#include "list_interface.h"

void InitList(LListPtr *L)
{
    (*L) = (NodePtr)malloc(sizeof(Node)); //生成头结点
    (*L)->next = *L; //头结点的指针域为空
}

//请根据教材自行完成下列函数的编码
bool InsList(LListPtr L, int i, ElemType e)
{
	NodePtr p = L->next, q;
	int k = 2; //因为p初始化为头结点的下一个，因此k就应该从2开始
    
    /*从"头"开始，查找第i-1个结点*/
	while (p != L && k < i)  /*表未查完且未查到第i-1个时重复，找到p指向第i-1个*/ 
	{ 
		p = p->next;
		++k; 
	}
    
	if (p == L && k < i)   /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
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
    return true;
}

void traverse(LListPtr L, CALLBACK f)
{
    NodePtr p = L->next;
	while (p != L)
	{
        f(&p->data);
        p = p->next;
	}
}

void DestroyList(LListPtr L)
{
    // NodePtr p = L->next, q;
	// while (p != L)
	// {
    //     q = p;
	// 	p = p->next;
	// 	free(q);
	// }
	NodePtr p = L, q;
	do
	{
        q = p;
		p = p->next;
		free(q);
	} while (p != L);
}