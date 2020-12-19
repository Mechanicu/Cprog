#include <stdio.h>

#include "graph.h"

/*用邻接矩阵法创建有向网的算法如下：*/

AdjType LocateVertex(Graph *G, VertexData v) /*求顶点位置函数*/
{
    for (AdjType k = 0; k < G->vexnum; k++)
        if (G->vertex[k].data == v)
            return k;

    return -1;
}

void CreateGraph(Graph *G) /*创建一个有向网*/
{
    int i, j, k, weight;
    int kind;
    VertexData v1, v2;

    //printf("输入图的顶点数和弧数\n");
    scanf("%d,%d,%d", &kind, &G->vexnum, &G->arcnum); /*输入图的顶点数和弧数*/
    getchar();

    G->kind = kind;

    for (i = 0; i < G->vexnum; i++)         /*初始化邻接矩阵*/
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j].adjvex = INFINITY;

    for (i = 0; i < G->vexnum; i++)
    {
        //printf("输入图的顶点\n");
        scanf("%c", &G->vertex[i].data); /* 输入图的顶点*/
    }
    getchar();

    for (k = 0; k < G->arcnum; k++)
    {
        //printf("输入一条弧的两个顶点及权值\n");
        scanf("%c,%c,%d", &v1, &v2, &weight); /*输入一条弧的两个顶点及权值*/
        getchar();
        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);
        G->arcs[i][j].adjvex = weight; /*建立弧*/
        if (G->kind > DN)
            G->arcs[j][i].adjvex = weight;
    }
}

void DestroyGraph(Graph *G)
{
    G->vexnum = G->arcnum = 0;
    G->kind = UNDEFINED;
}

void DrawGraph(Graph *G)
{
    putchar(' ');
    for (int i = 0; i < G->vexnum; ++i)
        printf("%4c", G->vertex[i].data);
    putchar('\n');

    for (int i = 0; i < G->vexnum; ++i)
    {
        printf("%c", G->vertex[i].data);
        for (int j = 0; j < G->vexnum; ++j)
            if (G->arcs[i][j].adjvex == INFINITY)
                printf("   %s", "∞");
            else
                printf("%4d", G->arcs[i][j].adjvex);
        putchar('\n');
    }
}

Arc FirstAdjVertex(struct Graph *G, AdjType v)
{
    Arc w;

    w.adj = -1;
    for (int j = 0; j < G->vexnum; ++j)
        if (G->arcs[v][j].adjvex == 1)
        {
            w.adj = j;
            break;
        }

    return w;
}

Arc NextAdjVertex(struct Graph *G, AdjType v, Arc w)
{
    Arc w2;

    w2.adj = -1;

    for (int j = w.adj + 1; j < G->vexnum; ++j)
        if (G->arcs[v][j].adjvex == 1)
        {
            w2.adj = j;
            break;
        }

    return w2;
}
