#include "function_declaration.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
static VertexID visit_seq[MAX_VERTEX_NUM];
static VertexID seq;
void init_gragh(gragh *G) //初始化图
{
    G->arcnum = G->vertexnum = 0;
}

#ifdef kinderfisher
INFO new_info_kf()
{
    int i = 0;
    char c;
    INFO info;
    printf("please input ID:\n");
    while ((c = getchar()) != '$')
        info.id[i++] = c;

    printf("please input weight:\n");
    scanf("%d", &info.weight);

    printf("please input length:\n");
    scanf("%d", &info.length);

    printf("please input name:\n");
    i = c = 0;
    getchar();
    while ((c = getchar()) != '$')
        info.name[i++] = c;

    info.Is_carnivorous = 1;
    info.Is_Marine = 0;

    printf("please input speed of this one:\n");
    scanf("%d", &info.speed);

    printf("please input color of this one:\n");
    i = c = 0;
    getchar();
    while ((c = getchar()) != '$')
        info.color[i++] = c;

    return info;
}
void visit_kf(INFOPTR info)
{
    if (info == NULL)
    {
        printf("there isn't any information about it\n");
        return;
    }
    printf("the id of kinderfisher is:%s\n", info->id);
    printf("the weight of it is:%d\n", info->weight);
    printf("the length of it is:%d\n", info->length);
    printf("the name of it is:%s\n", info->name);
    printf("the color of it is:%s\n", info->color);
    printf("the speed of it is:%d\n", info->speed);
    if (info->Is_carnivorous)
        printf("it's carnivorous\n");
    else
        printf("it's non-carnivorous\n");
    if (info->Is_Marine)
        printf("it's marine\n");
    else
        printf("it's non-marine\n");
}
void visit(gragh*G, int target)
{
    int i;
    for (i = 0; i < G->vertexnum; i++)
        if (G->vertex[i].firstvertex == target)
        {
            printf("%d:\n", target);
            //visit_kf(&G->vertex[i].info);
        }    
}
#endif //kinderfisher
// #ifdef

// #endif  //
// #ifdef

// #endif  //

int locate_vertex(gragh *G, VertexID v) //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
{
    if (!G->vertexnum)
    {
        printf("the gragh is empty\n");
        return -1;
    }
    int i;
    for (i = 0; i < G->vertexnum; i++)
        if (v == G->vertex[i].firstvertex)
            return i;
    if (i == G->vertexnum)
    {
        printf("no matched target,\n");
        return -1;
    }
}

bool insert_vertex(gragh *G, VertexID v)
{
    G->vertex[v].firstvertex = v;
    G->vertex[v].firstarc = NULL;
    //G->vertex[v].info = new_info_kf();
    return true;
}//不能用来插入，只能用于创建图！

bool insert_arc(gragh *G, VertexID des1, VertexID des2)
{
    if (G == NULL || locate_vertex(G, des1) == -1 || locate_vertex(G, des2) == -1)
    {
        printf("there isn't such vertex in the gragh.\n");
        return false;
    }
    int a = locate_vertex(G, des1), b = locate_vertex(G, des2);
    ANode *arcdes1 = G->vertex[a].firstarc;
    ANode *arcdes2 = G->vertex[b].firstarc;
    for (; arcdes1 != NULL; arcdes1 = arcdes1->nextarc)
        if (arcdes1->adjvex == des1)
            return false;
    arcdes1 = G->vertex[a].firstarc;
    ANode *ass1 = (ANode*)malloc(sizeof(ANode));
    ANode *ass2 = (ANode*)malloc(sizeof(ANode));
    ass1->adjvex = des2, ass1->nextarc = arcdes1;
    G->vertex[a].firstarc = ass1;
    ass2->adjvex = des1, ass2->nextarc = arcdes2;
    G->vertex[b].firstarc = ass2;
}

bool create_gragh(gragh *G)
{
    if (G->arcnum != 0 && G->vertexnum != 0)
    {
        printf("the gragh has already exsist.\n");
        return false;
    }
    int des1, des2;
    printf("please input the number of arc:");
    scanf("%d", &G->arcnum);
    printf("please input the number of vertex:");
    scanf("%d", &G->vertexnum);
    int i;
    printf("please input the information of everyone:\n");
    for (i = 0; i < G->vertexnum; i++)
    {
        printf("%d:\n", i);
        insert_vertex(G, i);
        //G->vertex[i].info = new_info_kf();
        putchar('\n');
    }//插入结点
    getchar();
    for (i = 0; i < G->arcnum; i++)
    {
        printf("please input the VertexID of both ends of arc:\n");
        printf("%d:\n",i);
        printf("first end:");scanf("%d", &des1);getchar();
        printf("second end:");scanf("%d", &des2);getchar();
        insert_arc(G, des1, des2);
    }//插入边
    return true;
}

void DFS_VertexID(gragh*G, int src, VertexID* visited)
{   
    visit(G, src);visited[src] = 1;
    visit_seq[seq++] = src;
    ANode* next = G->vertex[src].firstarc;
    while(next)
    {
        if (!visited[next->adjvex]) 
            DFS_VertexID(G, next->adjvex, visited);
        next = next->nextarc;
    }
}//递归实现深度优先遍历并输出信息

void DFS(gragh*G, int src, VertexID* visited)
{
    int i;
    seq = 0;
    for (i = 0; i < G->vertexnum; i++)
        visited[i] = 0;
    DFS_VertexID(G, src, visited);
    for (i = 0; i < seq; i++)
    {
        if(i != seq - 1) printf("%d-->",visit_seq[i]);
        else printf("%d\n", visit_seq[i]); 
    }
}

void BFS_VertexID(gragh*G, int src, VertexID* visited, RQUEUE* Q)
{
    VertexID visiting;
    visit(G, src);
    visited[src] = 1;
    visit_seq[seq++] = src;
    InitQueue(Q);
    EnterQueue(Q, src);
    ANode* W = NULL;
    while(!IsEmpty(Q))
    {
        DeleteQueue(Q, &visiting);
        W = G->vertex[visiting].firstarc;
        while(W)
        {
            if(!visited[W->adjvex])
            {
                visit(G, W->adjvex);
                visit_seq[seq++] = W->adjvex;
                visited[W->adjvex] = 1;
                EnterQueue(Q, W->adjvex);
            }
            W = W->nextarc;
        }
    }
    
}//递归实现广度优先遍历并输出信息

void BFS(gragh*G, int src, VertexID* visited, RQUEUE* Q)//按广度优先输出遍历顺序并按该顺序输出信息
{
    int i;
    seq = 0;
    for (i = 0; i < G->vertexnum; i++)
        visited[i] = 0;
    BFS_VertexID(G, src, visited, Q);
    for (i = 0; i < seq; i++)
    {
        if(i != seq - 1) printf("%d-->",visit_seq[i]);
        else printf("%d\n", visit_seq[i]); 
    }
}

void InitQueue(RQUEUE* Q)//初始化队列
{
    Q->rear = Q->front = 0;
}

bool EnterQueue(RQUEUE* Q, VertexID target)//数据进队
{
    ANode a;
    if (IsFull(Q)) {printf("the queue already full"); return 0;}
    Q->QueueElem[Q->rear] = target;
    Q->rear = (Q->rear+1) % MAX_VERTEX_NUM;
    return 1;
}

bool DeleteQueue(RQUEUE* Q, VertexID *target)//数据出队
{
    if (IsEmpty(Q)){printf("the queue is empty.\n"); return 0;}
    *target = Q->QueueElem[Q->front];
    Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
    return 1;
}

bool IsEmpty(RQUEUE* Q)//判断队是否空
{
    if (Q->front == Q->rear) return 1;
    else return 0;
}

bool IsFull(RQUEUE* Q)//判断队是否满
{
    if ((Q->rear + 1) % MAX_VERTEX_NUM == Q->front) return 1;
    else return 0;
}