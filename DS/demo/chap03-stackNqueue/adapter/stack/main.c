#include <stdio.h>

#include "stack.h"

void print(ElemType *v)
{
    printf("%4c", *v);
}

int main()
{
    stack s, *S = &s;

    stack_init(S);

    ElemType c;
    for (c = 'A'; c <= 'Z'; ++c)
        stack_push(S, c);
    stack_walk(S, print);

    for (int i = 0; i < 10; ++i)
    {
        c = stack_top(S);
        stack_pop(S);
    }

    printf("\nThe last popped: %c\n", c);
    stack_walk(S, print);
    putchar('\n');

    return 0;
}