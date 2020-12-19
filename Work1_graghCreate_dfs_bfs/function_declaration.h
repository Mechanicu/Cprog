#include"gragh_structure.h"
void init_gragh(gragh* G);//初始化图
int locate_vertex(gragh* G, VertexID v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(gragh *G, VertexID v);//插入节点
bool insert_arc(gragh *G, VertexID v, VertexID w);//插入边
bool create_gragh(gragh *G);//用于节点数组
//用于初始化图

#ifdef  kinderfisher
INFO new_info_kf();//用于每个kinderfisher的数据输入
void visit_kf(INFOPTR info);
#endif  //kinderfisher
#ifdef  rabbit
INFO new_info_rbt();//用于每个rabbit的信息输入
void visit_rbt(INFOPTR info);
#endif  //rabbit
#ifdef  hippopotamus
INFO new_info_hpt();//用于每个hippopotamus的信息输入
void visit_hpt(INFOPTR info);
#endif  //hippopotamus

void visit(gragh*G, int target);//访问节点数据
void DFS_VertexID(gragh*G, int src, VertexID* visited);//以结点编号为关键字的深度优先遍历
void DFS(gragh*G, int src, VertexID* visited);//按深度优先输出遍历顺序并按该顺序输出信息
void BFS_VertexID(gragh*G, int src, VertexID* visited, RQUEUE* Q);//以结点编号为关键字的广度优先遍历
void BFS(gragh*G, int src, VertexID* visited, RQUEUE* Q);//按广度优先输出遍历顺序并按该顺序输出信息

void InitQueue(RQUEUE* Q);//初始化队列
bool EnterQueue(RQUEUE* Q, VertexID target);//数据进队
bool DeleteQueue(RQUEUE* Q, VertexID *target);//数据出队
bool IsEmpty(RQUEUE* Q);//判断队是否空
bool IsFull(RQUEUE* Q);//判断队是否满