#include <stdio.h>
#include <stdbool.h>

#include "stack.h"

bool match(char *str)
{
    Stack s;
    char ch;

    init(&s);

    char *p = str;
    while (*p != '\0')
    {
        switch (*p)
        {
        case '(':
        case '{':
        case '[':
            push(&s, *p);
            break;

        case ')':
        case '}':
        case ']':
            ch = pop(&s);
            if (!(
                ch == '(' && *p == ')'
            ||  ch == '{' && *p == '}'
            ||  ch == '[' && *p == ']'
            ))
            {
                printf("Not match\n");
                return false;
            }
        }

        ++p;
    }

    if (empty(&s)) return true;

    clear(&s);
    return false;
}

int main()
{
    char *str = "({[[]]}{}";

    if (match(str))
        printf("Match!\n");
    else
        printf("Not match!\n");

    return 0;
}