#include "queue.h"

/*初始化操作*/
bool InitQueue(Queue *Q)
{  
	/* 将*Q初始化为一个空的循环队列 */
	Q->front=Q->rear=0;

    return true;
}

/*入队操作*/
bool EnterQueue(Queue *Q, QueueElementType x)
{  
	/*将元素x入队*/
	if(IsFull(Q))  /*队列已经满了*/
		return false;
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;  /* 重新设置队尾指针 */
	return true;  /*操作成功*/
}

/*出队操作*/
bool DeleteQueue(Queue *Q, QueueElementType *x)
{ 
	/*删除队列的队头元素，用x返回其值*/
	if (IsEmpty(Q))  /*队列为空*/
		return false;
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;  /*重新设置队头指针*/
	return true;  /*操作成功*/
}

bool GetHead(Queue *Q, QueueElementType *x)
{ 
	/*提取队列的队头元素，用x返回其值*/
	if(Q->front==Q->rear)  /*队列为空*/
		return false;
	*x=Q->element[Q->front];
	return true;  /*操作成功*/
}

bool IsEmpty(Queue *Q)
{ 
	/*提取队列的队头元素，用x返回其值*/
	// if(Q->front==Q->rear)  /*队列为空*/
	// 	return true;
	// else
	// 	return false;  /*操作成功*/
    return Q->front==Q->rear;
}

bool IsFull(Queue *Q)
{
    return (Q->rear+1) % MAXSIZE == Q->front;
}

void DestroyQueue(Queue *Q)
{
}