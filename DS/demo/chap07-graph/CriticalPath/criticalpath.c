#include <stdio.h>
#include <stdbool.h>

#include "../common/stack.h"
#include "../AdjList/graph.h"

static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称
static char *Vertex2Name(VertexData d)
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

int ve[MAX_VERTEX_NUM]; /*每个顶点的最早发生时间*/

bool TopoOrder(AdjList *G, Stack *T)
/* G为有向网，T为返回拓扑序列的栈，S为存放入度为0的顶点的栈*/
{
    int count, i, j, k;
    ArcNode *p;
    int indegree[MAX_VERTEX_NUM]; /*各顶点入度数组*/
    Stack S;

    InitStack(T);
    InitStack(&S);       /*初始化栈T,  S*/
    FindID(G, indegree); /*求各个顶点的入度*/

    for (i = 0; i < G->vexnum; ++i)
        if (indegree[i] == 0)
            Push(&S, i);

    count = 0;
    for (i = 0; i < G->vexnum; ++i)
        ve[i] = 0; /*初始化最早发生时间*/

    while (!IsEmpty(&S))
    {
        Pop(&S, &j);
        Push(T, j);
        ++count;
        p = G->vertex[j].firstarc;
        while (p != NULL)
        {
            k = p->adjvex;
            if (--indegree[k] == 0)
                Push(&S, k); /*若顶点的入度减为0，则入栈*/
            if (ve[j] + p->info.weight > ve[k])
                ve[k] = ve[j] + p->info.weight;
            p = p->nextarc;
        } /*while*/
    }     /*while*/

    return count >= G->vexnum;
}

bool CriticalPath(AdjList *G)
{
    ArcNode *p;
    int i, j, k, dut, ei, li;
    char tag;
    int vl[MAX_VERTEX_NUM]; /*每个顶点的最迟发生时间*/
    Stack T;

    if (!TopoOrder(G, &T))
        return false;

    for (i = 0; i < G->vexnum; ++i)
        vl[i] = ve[G->vexnum - 1]; /*初始化顶点事件的最迟发生时间*/

    while (!IsEmpty(&T))          /*按逆拓扑顺序求各顶点的vl值*/
    {
        Pop(&T, &j);
        p = G->vertex[j].firstarc;
        while (p != NULL)
        {
            k = p->adjvex;
            dut = p->info.weight;
            if (vl[k] - dut < vl[j])
                vl[j] = vl[k] - dut;
            p = p->nextarc;
        }                          /* while */
    }                              /* while*/
    for (j = 0; j < G->vexnum; ++j) /*求ei,li和关键活动*/
    {
        p = G->vertex[j].firstarc;
        while (p != NULL)
        {
            k = p->adjvex;
            dut = p->info.weight;
            ei = ve[j];
            li = vl[k] - dut;
            tag = (ei == li) ? '*' : ' ';
            printf("%s,%s,%d,%d,%d,%c\n", Vertex2Name(G->vertex[j].data), Vertex2Name(G->vertex[k].data), dut, ei, li, tag); /*输出关键活动*/
            p = p->nextarc;
        } /*while*/
    }     /* for */
    return true;
} /*CriticalPath*/

int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "criticalpath.in";
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

    CriticalPath(&G);
    putchar('\n');

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}