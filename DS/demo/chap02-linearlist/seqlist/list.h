#pragma once

#include <stdbool.h>

#include "list_elemtype.h"

#define	MAXSIZE  100   /*此处的宏定义常量表示线性表可能达到的最大长度*/

typedef  struct
{ 
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
	int       last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
} SeqList, LList, *LListPtr;

//prototype
extern void InitList(LListPtr *L);
extern bool InsList(LListPtr L, int i, ElemType e);
extern bool DelList(LListPtr L, int i, ElemType *e);

typedef void (*CALLBACK)(ElemType*);
//typedef void CALLBACK(ElemType*);

extern void traverse(LListPtr L, CALLBACK f);