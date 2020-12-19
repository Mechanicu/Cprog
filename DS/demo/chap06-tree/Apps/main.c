#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../CSTree/BiTree.h"
#include "queue.h"

#define EOL putchar('\n')

void print(DataType e)
{
    printf("%2c", e);
}

bool like(BiTree t1, BiTree t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    else if (t1 == NULL || t2 == NULL)
        return false;

    bool ll = like(t1->LChild, t2->LChild);
    bool lr = like(t1->RChild, t2->RChild);

    return ll && lr;
}

void LayerOrder(BiTree root, CALLBACK visit)
{
    if (root == NULL)
        return;

    Queue q, *Q = &q;
    BiTree p;

    InitQueue(Q);

    EnterQueue(Q, root);
    while (!IsEmpty(Q))
    {
        DeleteQueue(Q, &p);

        visit(p->data);

        if (p->LChild != NULL)
            EnterQueue(Q, p->LChild);
        if (p->RChild != NULL)
            EnterQueue(Q, p->RChild);
    }

    DestroyQueue(Q);
}

int main(int argc, char *argv[])
{
    char *const nodes1 = "ABDHL..M...E.I..CF.JN...G.K..";
    char *const nodes2 = "12345..6...7.8..9A.BC...D.E.F..";
    BiTree t1 = NULL, t2 = NULL;

    char *p = nodes1;
    t1 = CreateBiTree(&p);
    p = nodes2;
    t2 = CreateBiTree(&p);

    PreOrder(t1, print);
    EOL;
    PreOrder(t2, print);
    EOL;

    printf("t1 is %s t2\n", like(t1, t2) ? "like" : "not like");

    LayerOrder(t1, print);
    EOL;

    DestroyBiTree(t1);
    DestroyBiTree(t2);

    return 0;
}
