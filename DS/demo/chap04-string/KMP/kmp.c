#include <stdio.h>

#define MAXLEN 128

typedef struct 
{
    char ch[128];
    int len;
} String;

static int c_style_strlen(char *t)
{
    char *p = t;

    if (t == NULL) return 0;

    while (*p != '\0') ++p;
    return p - t;
}

static void c_style_strcpy(char *s, char *t)
{
    if (s == NULL || t == NULL) return;
    while (*t != '\0') *s++ = *t++;
}

int StrSet(String *s, char *t)
{
    int l = c_style_strlen(t);

    if (l < 0 || l >= MAXLEN)
    {
        s->len = 0;
        return 0;
    }

    c_style_strcpy(s->ch, t);
    return s->len = l;
}

//https://www.cnblogs.com/DWVictor/p/10328320.html
static void Getnext(String *t, int next[])
{
    int j = 0, k = -1;

    next[0] = -1;
    while (j < t->len - 1)
    {
        if (k == -1 || t->ch[j] == t->ch[k])
        {
            if (t->ch[++j] == t->ch[++k])
                next[j] = next[k];
            else
                next[j] = k;
        }
        else
            k = next[k];
    }
}

int KMP(String *s, String *t)
{
    int next[MAXLEN], i = 0, j = 0;

    Getnext(t, next);
    for (int i = 0; i < t->len; ++i) printf("%4d", next[i]);
    putchar('\n');

    while (i < s->len && j < t->len)
    {
        printf("before: i=%d, j=%d     ", i, j);
        if (j == -1 || s->ch[i] == t->ch[j])
        {
            ++i;
            ++j;
        }
        else 
            j = next[j];  //j回退。。。
        printf("after: i=%d, j=%d\n", i, j);
    }

    return j >= t->len ? i - t->len : -1;
}

int main()
{
    String s1, q1;

    StrSet(&s1, "ababcabcacbab");
    StrSet(&q1, "abcac");
    printf("%d\n", KMP(&s1, &q1));
}