#include <stdio.h>
#include <malloc.h>

#include "string.h"

int StrSet(String *s, char *t)
{
    int i;
    char *p = t;

    while (*p) ++p;
    s->len = p - t;

    s->ch = (char *)malloc(s->len);
    for (i = 0; i < s->len; ++i)
        s->ch[i] = t[i];
    return s->len;
}

void StrDestroy(String *s)
{
    free(s->ch);
}

int StrPrint(String *s)
{
    for (int i = 0; i < s->len; ++i)
        putchar(s->ch[i]);
    return s->len;
}

void StrCopy(String *s, String *t)
{
    free(s->ch);
    s->ch = (char *)malloc(t->len);
    for (int i = 0; i < t->len; ++i)
        s->ch[i] = t->ch[i];
    s->len = t->len;
}