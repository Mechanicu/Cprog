#include <stdio.h>

#include "TSMatrix.h"

//algo 5.2
void TransposeTSMatrix(TSMatrix *from, TSMatrix *to)
{
    int i, j, k;

    to->m = from->n;
    to->n = from->m;
    to->len = from->len;

    if (to->len == 0)
        return;

    j = 1;                         /*j为辅助计数器，记录转置后的三元组在三元组表B中的下标值*/
    for (k = 1; k <= from->n; k++) /*扫描三元组表A 共k次，每次寻找列值为k的三元组进行转置*/
        for (i = 1; i <= from->len; i++)
            if (from->data[i].col == k)
            {
                to->data[j].row = from->data[i].col;
                to->data[j].col = from->data[i].row;
                to->data[j].e = from->data[i].e;
                ++j;
            }
}

//algo 5.3
void FastTransposeTSMatrix(TSMatrix *from, TSMatrix *to)
{
    /*基于矩阵的三元组表示，采用"按位快速转置"法，将矩阵A转置为矩阵B*/
    int col, t, p, q;
    int num[MAXSIZE], position[MAXSIZE];
    to->len = from->len;
    to->n = from->m;
    to->m = from->n;
    if (to->len)
    {
        for (col = 1; col <= from->n; col++)
            num[col] = 0;
        for (t = 1; t <= from->len; t++)
            num[from->data[t].col]++; /*计算每一列的非零元素的个数*/
        position[1] = 1;
        for (col = 2; col <= from->n; col++) /*求col列中第一个非零元素在B.data[ ]中的正确位置*/
            position[col] = position[col - 1] + num[col - 1];
        for (p = 1; p <= from->len; p++) /*将被转置矩阵的三元组表A从头至尾扫描一次，实现矩阵转置*/
        {
            col = from->data[p].col;
            q = position[col];
            to->data[q].row = from->data[p].col;
            to->data[q].col = from->data[p].row;
            to->data[q].e = from->data[p].e;
            position[col]++; /* position[col]加1，指向下一个列号为col的非零元素在三元组表B中的下标值*/
        }                    /*end of for*/
    }
}

void ShowTSMatrix(TSMatrix *M, const char *msg)
{
    printf("%s\n", msg);
    for (int i = 1; i <= M->len; ++i)
        printf("(%4d, %4d, %4d)\n", M->data[i].row, M->data[i].col, M->data[i].e);
}

void PrintfTSMatrix(TSMatrix *M, const char *msg)
{
    int i, j, k = 1;
    Triple *t;

    printf("%s\n", msg);
    for (i = 1; i <= M->m; ++i)
    {
        for (j = 1; j <= M->n; ++j)
        {
            t = &M->data[k];
            printf("%4d", t->row == i && t->col == j ? (++k, t->e) : 0);
        }
        putchar('\n');
    }
}

//请自行在todo后添加语句完成算法
bool AddTSMatrix(TSMatrix *A, TSMatrix *B, TSMatrix *C)
{
    int i, j, k;
    int arow, acol, brow, bcol;

    //todo: 如果A和B不同质，则返回假

    i = j = k = 1; //i游标用于扫描A，j游标用于扫描j，k游标用于扫描C

    //todo: 这里要用几条语句，填充基础数据到C中

    while (i <= A->len && j <= B->len)
    {
        //todo: 获取A、B的行号、列号到arow,acol,brow,bocl

        if (arow < brow)
            ;//todo: i游标下的元组在前，因此将其插入到C的第k行，然后i自增
        else if (arow > brow)
            ;//todo: 插入j元组到位置k
        else
        {
            ;//TODO：比较列号，处理方法同比较行号。不同之处在于，如果列号相同（此时行号也相同），则需要合并两个元组
        }
        ++C->len;
        ++k;
    }

    //todo: 处理A或B中剩余的元组

    return true;
}