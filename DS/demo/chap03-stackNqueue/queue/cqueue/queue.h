#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

#include "queue_elemtype.h"

#define MAXSIZE 10  /*队列的最大长度*/

typedef struct
{
	QueueElementType  element[MAXSIZE];  /* 队列的元素空间*/
	int front;  /*头指针指示器*/
	int rear;  /*尾指针指示器*/
} SeqQueue, Queue;

extern bool InitQueue(Queue *Q);
extern bool EnterQueue(Queue *Q, QueueElementType x);
extern bool DeleteQueue(Queue *Q, QueueElementType *x);
extern bool GetHead(Queue *Q, QueueElementType *x);
extern bool IsEmpty(Queue *Q);
extern bool IsFull(Queue *Q);
extern void DestroyQueue(Queue *Q);