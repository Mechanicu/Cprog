#pragma once

#include <stdbool.h>

#define MAXSIZE 50  /*非零元素的个数最多为1000*/
#define ElementType int

/*稀疏矩阵三元组表的类型定义*/	
typedef struct
{   
	int row,col;  /*该非零元素的行下标和列下标*/
    ElementType e; /*该非零元素的值*/
} Triple;

typedef struct
{  
    int m,n,len;          /*矩阵的行数、列数和非零元素的个数*/
	Triple data[MAXSIZE+1];   /* 非零元素的三元组表。data[0]未用*/
} TSMatrix;

extern void TransposeTSMatrix(TSMatrix *from, TSMatrix *to);
extern void FastTransposeTSMatrix(TSMatrix *from, TSMatrix *to);
extern void ShowTSMatrix(TSMatrix *M, const char *msg);
extern void PrintfTSMatrix(TSMatrix *M, const char *msg);

extern bool AddTSMatrix(TSMatrix *A, TSMatrix *B, TSMatrix *C);