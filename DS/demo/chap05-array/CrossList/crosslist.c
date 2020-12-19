#include <stdio.h>
#include <malloc.h>

#include "crosslist.h"

//请自行在todo处添加代码完成算法
//注意：本算法只是一种思路，不能完全照搬
void CreateCrossList(CrossList *M, OLNode nodes[], int m, int n, int len)
{
    OLNode *p, *q;
    int i, j, k, e;

    //TODO：填充基础数据到M

    //TODO：生成行、列向量（为其分配空间），将所有元素置为NULL

    for(k = 1; k <= len; ++k)
    {
        //TODO：生成新节点p，从nodes[k]出填充数据到p

        //TODO：在第i行方向的单链表中找到合适位置，插入p节点（用到right）

        //TODO：在第j列方向的单链表中找到合适位置，插入p节点（用到down）
    }
}

void PrintCrossList(CrossList *M, int row_or_col)
{
    OLNode *p;
    OLink *head;
    int i, l;

    if (row_or_col == 0)
    {
        l = M->m;
        head = M->row_head;
        printf("Printed by row\n");
    }
    else
    {
        l = M->n;
        head = M->col_head;
        printf("Printed by col\n");
    }

    for (i = 1; i <= l; ++i)
        for (p = head[i]; p != NULL;)
        {
            printf("(%d, %d, %d)\n", p->row, p->col, p->value);
            p = row_or_col == 0 ? p->right : p->down;
        }
}

void DestroyCrossList(CrossList *M)
{
    OLNode *p, *q;
    int i;

    for (i = 1; i <= M->m; ++i)
    {
        p = M->row_head[i];
        while (p != NULL)
        {
            q = p;
            p = p->right;
            free(q);
        }
    }

    free(M->row_head);
    free(M->col_head);
}

// void CreateCrossList(CrossList *M)
// {
// 	int m,n,t;
// 	OLNode *p,*q;
// 	int i,j,e;
// 	/*采用十字链表存储结构，创建稀疏矩阵M*/
// 	printf("输入M的行数,列数和非零元素的个数\n");
// 	scanf("%d,%d,%d",&m,&n,&t);  /*输入M的行数,列数和非零元素的个数*/
// 	M->m=m;
// 	M->n=n;
// 	M->len=t;
// 	if(!(M->row_head=(OLink *)malloc((m+1)*sizeof(OLink)))) 
// 		printf("error");
// 	if(!(M->col_head=(OLink *)malloc((n+1)*sizeof(OLink)))) 
// 		printf("error");
// 	M->row_head=M->col_head=NULL;   /*初始化行、列头指针向量，各行、列链表为空的链表*/

// 	printf("输入\n");
// 	for(scanf("%d,%d,%d",&i,&j,&e);i!=0;scanf("%d,%d,%d",&i,&j,&e))
// 	{
// 		if(!(p=(OLNode *)malloc(sizeof(OLNode)))) 
// 			printf("error");
// 		p->row=i;
// 		p->col=j;
// 		p->value=e;  /*生成结点*/
// 		if(M->row_head[i]==NULL)   
// 			M->row_head[i]=p;
// 		else
// 		{  
// 			/*寻找行表中的插入位置*/
// 			for(q=M->row_head[i];q->right&&q->right->col<j;q=q->right);  /*空循环体*/
// 			p->right=q->right; 
// 			q->right=p;  /*完成插入*/
// 		}
// 		if(M->col_head[j]==NULL)   
// 			M->col_head[j]=p;
// 		else
// 		{  
// 			/*寻找列表中的插入位置*/
// 			for(q=M->col_head[j];q->down&&q->down->row<i;q=q->down);  /*空循环体*/
// 			p->down=q->down; 
// 			q->down=p;   /*完成插入*/
// 		}
// 	}
// }