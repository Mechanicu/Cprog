#include <stdio.h>

#include "string.h"

int StrSet(String *s, char *t)
{
    int i;
    
    for (i = 0; i < MAXLEN && t[i] != '\0'; ++i)
        s->ch[i] = t[i];
    return s->len = i;
}

int StrPrint(String *s)
{
    for (int i = 0; i < s->len; ++i)
        putchar(s->ch[i]);
    return s->len;
}

void StrCopy(String *s, String *t)
{
    for (int i = 0; i < t->len; ++i)
        s->ch[i] = t->ch[i];
    s->len = t->len;
}

bool StrInsert(String *s, int pos, String *t)
{
    if (pos < 0 || pos > s->len || t->len == 0)
        return false;

    int mstart, mend, cend;

    if (s->len + t->len <= MAXLEN)
    {
        mstart = s->len + t->len - 1;
        mend = pos + t->len;
        cend = mend;
    }
    else if (pos + t->len <= MAXLEN)
    {
        mstart = MAXLEN - 1;
        mend = pos + t->len;
        cend = mend;
    }
    else
    {
        mstart = -1;
        mend = 0;
        cend = MAXLEN - 1;
    }

    int i;
    for (i = mstart; i >= mend; --i)
        s->ch[i] = s->ch[i - t->len];
    for (i = pos; i < cend; ++i)
        s->ch[i] = t->ch[i - pos];

    s->len += t->len;
    
    return 0;
}

//algo 4.4
//Brute-Force算法，又称为暴力算法
int StrIndex(String *s,int pos, String *t) 
/*求从主串s的下标pos起，串t第一次出现的位置，成功返回位置序号，不成功返回-1*/
{ 
    int i, j, start;
    if (t->len == 0)  
        return 0;   /* 模式串为空串时，是任意串的匹配串 */

    start=pos; 
    i=start; 
    j=0;  /* 主串从pos开始，模式串从头（0）开始 */
    while (i<s->len && j<t->len)
    {
        if (s->ch[i]==t->ch[j]) 
        {
            i++;
            j++;
        }   /* 当前对应字符相等时推进 */
        else 
        { 
            start++;        /* 当前对应字符不等时回溯 */
            i=start; 
            j=0;   /* 主串从start+1开始，模式串从头（0）开始*/
        } 
    }

    if (j>=t->len) 
        return(start);    /* 匹配成功时，返回匹配起始位置 */
    else 
        return(-1);    /* 匹配不成功时，返回-1 */
}