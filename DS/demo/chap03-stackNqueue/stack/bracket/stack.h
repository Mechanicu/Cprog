#pragma once

#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
} Node, Stack, *StackPtr;

extern void init(StackPtr s);
extern void push(StackPtr s, char c);
extern char pop(StackPtr s);
extern bool empty(StackPtr s);
extern void clear(StackPtr s);