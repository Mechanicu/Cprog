#include <stdbool.h>

#define BLOCK_SIZE  4

typedef struct _block
{
    char ch[BLOCK_SIZE];
    struct _block *next;
} block, *blockptr;

typedef struct 
{
    blockptr head, tail;
    int len;
} String;

// extern bool StrInsert(String *s, int pos, String *t);
// extern bool StrDelete(String *s, int pos, int len);
// extern void StrCopy(String *s, String *t);
// extern int StrCompare(String *s, String *t);
// extern blockptr StrIndex(String *s, String *t);
extern bool StrEmpty(String *s);
extern int StrLength(String *s);
extern void StrClear(String *s);
// extern bool StrCat(String *s, String *t);
// extern bool SubString(String *sub, String *s, int pos, int len);
extern void StrDestroy(String *s);
// extern int StrReplace(String *s, String *p, String *r);

extern int StrSet(String *s, char *t);
extern int StrPrint(String *s);

// extern int StrIndexKMP(String *s, String *t);