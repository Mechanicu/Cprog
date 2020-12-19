#include <stdbool.h>

typedef struct 
{          /*串结构定义*/
    char *ch;
    int len;
} String;

extern bool StrInsert(String *s, int pos, String *t);
extern bool StrDelete(String *s, int pos, int len);
extern void StrCopy(String *s, String *t);
extern int StrCompare(String *s, String *t);
extern int StrIndex(String *s, int pos, String *t);
extern bool StrEmpty(String *s);
extern int StrLength(String *s);
extern void StrClear(String *s);
extern bool StrCat(String *s, String *t);
extern bool SubString(String *sub, String *s, int pos, int len);
extern void StrDestroy(String *s);
extern int StrReplace(String *s, String *p, String *r);

extern int StrSet(String *s, char *t);
extern int StrPrint(String *s);