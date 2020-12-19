#pragma once

#include <stdbool.h>

#include "list.h"

//prototype
extern void InitList(LListPtr *L);
extern bool InsList(LListPtr L, int i, ElemType e);
extern bool DelList(LListPtr L, int i, ElemType *e);
extern void DestroyList(LListPtr L);

typedef void (*CALLBACK)(ElemType*);
//typedef void CALLBACK(ElemType*);

extern void traverse(LListPtr L, CALLBACK f);