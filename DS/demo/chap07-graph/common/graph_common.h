#pragma once

#define INFINITY 32768    /*表示极大值，即∞*/

#define MAX_VERTEX_NUM 20 /*最多顶点个数*/

typedef enum
{
    UNDEFINED = 0,
    DG,
    DN,
    UDG,
    UDN
} GraphKind;   /*图的种类：DG表示有向图, DN表示有向网, UDG表示无向图, UDN表示无向网*/

typedef char VertexData; /*假设顶点数据为字符型*/
typedef int AdjType;

typedef struct OtherInfo
{
    int weight;
} OtherInfo;

//超前声明
struct ArcNode;  //forwarding
struct VertexNode;  //forwarding
struct Graph;  //forwarding

typedef struct
{
    AdjType adj;
    struct ArcNode *arc;
}  Arc;

extern AdjType LocateVertex(struct Graph *G, VertexData v);
extern void CreateGraph(struct Graph *G);
extern void DestroyGraph(struct Graph *G);
extern void DrawGraph(struct Graph *G);

extern Arc FirstAdjVertex(struct Graph *G, AdjType v);
extern Arc NextAdjVertex(struct Graph *G, AdjType v, Arc w);
