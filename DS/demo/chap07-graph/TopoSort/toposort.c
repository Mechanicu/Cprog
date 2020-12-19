#include <stdio.h>
#include <stdbool.h>

#include "../common/stack.h"
#include "../AdjList/graph.h"

static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称
static char * Vertex2Name(VertexData d)
{
    return vertex_map[d - 'A'];
}

void FindID(AdjList *G, int indegree[])
/*求各顶点的入度*/
{
    int i;
    ArcNode *p;

    for (i = 0; i < G->vexnum; ++i)
        indegree[i] = 0;

    for (i = 0; i < G->vexnum; ++i)
    {
        p = G->vertex[i].firstarc;
        while (p != NULL)
        {
            ++indegree[p->adjvex];
            p = p->nextarc;
        }
    } /* for */
}

bool TopoSort(AdjList *G)
{
    Stack S;
    int indegree[MAX_VERTEX_NUM];
    int i, count, k;
    ArcNode *p;

    FindID(G, indegree); /*求各顶点入度*/
    InitStack(&S);       /*初始化辅助栈*/

    for (i = 0; i < G->vexnum; ++i)
        if (indegree[i] == 0)
            Push(&S, i); /*将入度为0的顶点入栈*/

    count = 0;
    while (!IsEmpty(&S))
    {
        Pop(&S, &i);
        printf("%s  ", Vertex2Name(G->vertex[i].data));
        ++count; /*输出i号顶点并计数*/
        p = G->vertex[i].firstarc;
        while (p != NULL)
        {
            k = p->adjvex;
            --indegree[k]; /*i号顶点的每个邻接点的入度减1*/
            if (indegree[k] == 0)
                Push(&S, k); /*若入度减为0，则入栈*/
            p = p->nextarc;
        }
    } /*while*/

    return count < G->vexnum ? false : true; /*false意味着该有向图含有回路*/
}

int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "toposort.in";
    Graph G;

    if (freopen(datafile, "r", stdin) == NULL)
    {
        fprintf(stderr, "Cannot open data file '%s'\n", datafile);
        return -1;
    };

    CreateGraph(&G);
    DrawGraph(&G);
    putchar('\n');

    for (int i = 0; i < G.vexnum; ++i)
        scanf("%s", vertex_map[i]);
    getchar();

    TopoSort(&G);
    putchar('\n');

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}