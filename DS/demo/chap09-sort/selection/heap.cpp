#include "../record.h"

static void sift(RecordType r[], int k, int m)
/* 假设ｒ[k..m]是以ｒ[k]为根的完全二叉树，且分别以ｒ[2k]和ｒ[2k+1]为根的左、右子树为大根堆，调整r[k]，使整个序列r[k..m]满足堆的性质 */
{
    RecordType t = r[k]; /* 暂存"根"记录r[k] */
    bool finished = false;

    int i = k; //i是子树的根节点序号
    int j = 2 * i; //初始时，j是i的左孩子序号
    //沿着i的孩子j，往下筛选
    while (j <= m && !finished)
    {
        if (j < m && r[j].key < r[j + 1].key) //j+1是i右孩子的序号
            ++j; /* 若存在右子树，且右子树根的关键字大，则沿右分支"筛选" */
        if (t.key >= r[j].key)
            finished = true; /*  筛选完毕  */
        else
        {
            r[i] = r[j]; //子树的根节点被其值最大的那个孩子覆盖
            i = j;   //以j为子树的根，进行下一趟筛选
            j = 2 * i;
        } /* 继续筛选 */
    }
    //i已经不再是原来的i，而是原来的某个深度的孩子的序号
    r[i] = t; /* 原来的根r[k]填入到恰当的位置 */
}

static void create_heap(RecordType r[], int length)
/*对记录数组r建堆，length为数组的长度*/
{
    for (int i = length / 2; i >= 1; --i) /* 自第[n/2]个记录开始进行筛选建堆 */
        sift(r, i, length);
}

void HeapSort(RecordType r[], int length)
/* 对r[1..n]进行堆排序，执行本算法后，r中记录按关键字由大到小有序排列 */
{
    RecordType b;

    create_heap(r, length);

    for (int i = length; i >= 2; --i)
    {
        /* 将堆顶记录和堆中的最后一个记录互换 */
        b = r[1];
        r[1] = r[i];
        r[i] = b;

        /* 进行调整，使r[1..i-1]变成堆 */
        sift(r, 1, i - 1);
    }
} /* HeapSort */