#pragma once

#include "list_elemtype.h"

typedef struct _node
{ 
	ElemType data;
	struct _node  *next, *prior;
} Node, *NodePtr, LList, *LListPtr;