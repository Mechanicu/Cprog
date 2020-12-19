#include <stdio.h>
#include <malloc.h>

#include "string.h"

bool StrEmpty(String *s)
{
    return s->len == 0;
}

int StrLength(String *s)
{
    return s->len;
}

void StrClear(String *s)
{
    blockptr p, q;

    if (s == NULL) 
        return;

    p = s->head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    s->head = s->tail = NULL;
    s->len = 0;
}


void StrDestroy(String *s)
{
    StrClear(s);
}


int StrSet(String *s, char *t)
{
    blockptr p;
    int i;

    if (t == NULL || t[0] == '\0') 
        return 0;

    s->head = s->tail = NULL;
    s->len = 0;

    while (*t)
    {
        p = (blockptr)malloc(sizeof(block));
        p->next = NULL;
        for (i = 0; i < BLOCK_SIZE && *t != '\0'; ++i, ++t)
            p->ch[i] = *t;

        for (; i < BLOCK_SIZE; ++i)
            p->ch[i] = '#';

        if (s->tail == NULL)
            s->head = p;
        else
            s->tail->next = p;
        s->tail = p;

        ++s->len;
    }

    return s->len;
}

int StrPrint(String *s)
{
    blockptr p;
    char *t;
    int i;
    
    if (s == NULL || s->head == NULL)
        return 0;
        
    p = s->head;
    while (p != NULL)
    {
        t = p->ch;
        for (i = 0; i < BLOCK_SIZE && *t != '#'; ++i, ++t)
            putchar(*t != ' ' ? *t : '_');
        p = p->next;
    }

    return s->len;
}