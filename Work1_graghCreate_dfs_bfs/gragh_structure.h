#include"info_structure.h"
#define MAX_VERTEX_NUM 50
typedef int VertexID;

typedef struct ArcNode
{
    VertexID adjvex;
    struct ArcNode *nextarc;
}ANode;

typedef struct VertexNode
{
    VertexID firstvertex;
    INFO info;
    ANode *firstarc;
}VNode;

typedef struct XXX_gragh
{
    int arcnum, vertexnum;
    VNode vertex[MAX_VERTEX_NUM];
}gragh;

typedef struct queue
{
    int front, rear;
    VertexID QueueElem[MAX_VERTEX_NUM];
}RQUEUE;