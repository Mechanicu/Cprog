#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI  3.1415926
//const double PI = 3.1415926;

// struct _circle
// {
//     double x, y;
//     double r;
// };
// typedef old_type new_type;
// typedef int A[5];
// typedef struct _circle circle; // alias
typedef struct 
{
    double x, y;
    double r;
} circle;

double area(circle *c)
{
    return c->r * c->r * PI;
}

circle make_circle()
{
    circle t;
    t.x = rand() % 100;
    t.y = rand() % 100;
    t.r = rand() % 10;

    return t;
}

int main()
{
    circle c;
    int i;

    srand(time(NULL));

    for (i = 0; i < 5; ++i)
    {
        c = make_circle();
        printf("(%.2lf,%.2lf)=>%.2lf\n", c.x, c.y, area(&c));
    }
    
    return 0;
}