#include"function.h"
int	main()
{
    gragh* G = (gragh*)malloc(sizeof(gragh));
    create_gragh(G);
    VertexID visited[G->vertexnum];
    RQUEUE Q;
    int i;
    DFS(G, 0, visited);
    BFS(G, 0, visited, &Q);
    return 0;
}
