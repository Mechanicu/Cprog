#include <stdio.h>

#include "../AdjMatrix/graph.h"

/*普里姆算法描述如下：*/
typedef struct
{
    AdjType adjvex;
    int lowcost;
} CloseEdge[MAX_VERTEX_NUM];

AdjType Minium(CloseEdge ce, int n)
{
    int i, j = -1;
    int c = -1;

    for (i = 0; i < n; ++i)
        if (ce[i].lowcost != 0 && (c == -1 || c > ce[i].lowcost))
        {
            c = ce[i].lowcost;
            j = i;
        }

    return j;
}

static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称
static char * Vertex2Name(VertexData d)
{
    return vertex_map[d - 'A'];
}

void MiniSpanTree_Prim(AdjMatrix *gn, VertexData k)
/*从顶点u出发，按普里姆算法构造连通网gn 的最小生成树，并输出生成树的每条边*/
{
    int i, e;
    AdjType u, v;
    CloseEdge closedge; /* 求最小生成树时的辅助数组*/

    u = LocateVertex(gn, k);
    closedge[u].lowcost = 0; /*初始化，U={u} */
    for (i = 0; i < gn->vexnum; ++i)
        if (i != u) /*对V-U中的顶点i，初始化closedge[i]*/
        {
            closedge[i].adjvex = u;
            closedge[i].lowcost = gn->arcs[u][i].adjvex;
        }

    for (e = 1; e <= gn->vexnum - 1; ++e) /*找n-1条边(n= gn.vexnum) */
    {
        v = Minium(closedge, gn->vexnum);       /* closedge[v]中存有当前最小边（u,v）的信息*/
        u = closedge[v].adjvex;    /* u∈U*/
        printf("(%s, %s, %d)\n", 
        Vertex2Name(gn->vertex[u].data), 
        Vertex2Name(gn->vertex[v].data),
        closedge[v].lowcost);     /*输出生成树的当前最小边（u,v）*/

        closedge[v].lowcost = 0;    /*将顶点v纳入U集合*/
        for (i = 0; i < gn->vexnum; ++i) /*在顶点v并入U之后，更新closedge[i]*/
            if (gn->arcs[v][i].adjvex < closedge[i].lowcost)
            {
                closedge[i].lowcost = gn->arcs[v][i].adjvex;
                closedge[i].adjvex = v;
            }
    }
}

int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "prim.in";
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
    
    MiniSpanTree_Prim(&G, 'A');

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}