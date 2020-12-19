#include <stdio.h>

//#define NONRECURSIVE

#ifdef NONRECURSIVE
#include "../common/stack.h"
#endif

#include "search.h"

#ifndef NONRECURSIVE
/*用邻接表方式实现深度优先搜索*/
void Search(Graph *g, int v0, CALLBACK visit) /*图g为邻接表类型AdjList */
{
    visit(g->vertex[v0].data);
    visited[v0] = true;

    ArcNode *p = g->vertex[v0].firstarc;
    while (p != NULL)
    {
        if (!visited[p->adjvex])
            Search(g, p->adjvex, visit);
        p = p->nextarc;
    }
} /*DepthFirstSearch*/

#else

void Search(Graph *g, int v0, CALLBACK visit) /*广度优先搜索图g中v0所在的连通子图*/
{
    Stack s, *S = &s;
    ArcNode *p;
    int w, v;

    InitStack(S); /*初始化空队*/

    Push(S, v0);
    while (!IsEmpty(S))
    {
        Pop(S, &v);
        if (!visited[v])
        {
            visit(g->vertex[v].data);
            visited[v] = true;
        }
        p = g->vertex[v].firstarc;
        while (p != NULL)
        {
            w = p->adjvex;
            if (!visited[w])
                Push(S, w);
            p = p->nextarc;
        }
    }

    ClearStack(S);
}
#endif