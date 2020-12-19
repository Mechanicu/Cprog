#include <stdio.h>
#include <stdbool.h>

#include "../AdjMatrix/graph.h"

typedef struct
{
    AdjType u, v;
    int lowcost;
} Edge;

int VertexSet[MAX_VERTEX_NUM];

bool Minium(Graph *G, Edge *e)
{
    int i, j;

    e->u = e->v = -1;
    e->lowcost = INFINITY;
    for (i = 0; i < G->vexnum; ++i)
        for (j = 0; j < G->vexnum; ++j)
            if (e->lowcost > G->arcs[i][j].adjvex && VertexSet[i] != VertexSet[j])
            {
                e->lowcost = G->arcs[i][j].adjvex;
                e->u = i;
                e->v = j;
            }

    return e->u != -1;
}

static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称
static char *Vertex2Name(VertexData d)
{
    return vertex_map[d - 'A'];
}

void MiniSpanTree_Kruskal(AdjMatrix *gn)
{
    Edge e;
    int i, setid;
    int u, v;

    for (i = 0; i < gn->vexnum; ++i)
        VertexSet[i] = i;
    setid = i;

    while (Minium(gn, &e))
    {
        printf("(%s, %s, %d)\n",
               Vertex2Name(gn->vertex[e.u].data),
               Vertex2Name(gn->vertex[e.v].data),
               e.lowcost); /*输出生成树的当前最小边（u,v）*/

        u = VertexSet[e.u];
        v = VertexSet[e.v];
        for (i = 0; i < gn->vexnum; ++i)
            if (VertexSet[i] == u || VertexSet[i] == v)
                VertexSet[i] = setid;
        ++setid;
    }
}

int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "kruskal.in";
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

    MiniSpanTree_Kruskal(&G);

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}