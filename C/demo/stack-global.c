#include <stdio.h>
#include <stdlib.h>

//type alias
//you can substitute 'int' with any type, such as float
typedef int value_type;
typedef int bool;

#define MAX_DEPTH 1024

value_type stack[MAX_DEPTH];
int top = 0;

bool is_full() { return top == MAX_DEPTH; }
bool is_empty() { return top == 0; }

void overflow() 
{
    printf("Push failed: the stack is full.\n");
    exit(EXIT_FAILURE);
}

void underflow() 
{
    printf("Pop failed: the stack is empty.\n");
    exit(EXIT_FAILURE);
}

void push(value_type e)
{
    if (is_full())
        overflow();
    else
        stack[top++] = e;
}

value_type pop()
{
    if (is_empty())
        underflow();
    else
        return stack[--top];
}

int main()
{
    int i;
    value_type t;
    for (i = 0; i <=4; ++i) push(i);

    t = pop();
    printf("%d, %d\n", t, pop());

    pop(); pop(); pop(); 
    pop(); //this will cause underflow

    return 0;
}