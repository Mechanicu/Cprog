#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "stack.h"

void init(StackPtr s)
{
    s->next = NULL;
}

void push(StackPtr s, char c)
{
    Node* p = (Node *)malloc(sizeof(Node));
    p->data = c;

    p->next = s->next;
    s->next = p;
}

char pop(StackPtr s)
{
    Node* p = s->next;

    if (p == NULL)
    {
        printf("Stack underflow!");
        exit(0);
    }

    char c = p->data;
    s->next = p->next;
    free(p);

    return c;
}

bool empty(StackPtr s)
{
    return s->next == NULL;
}

void clear(StackPtr s)
{
    Node* p = s->next, *q;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    s->next = NULL;
}