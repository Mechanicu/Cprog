#include <malloc.h>
#include <cstdlib>

#include "../record.h"

static int key_size = 0;

#define Order(r) (r);

static void Distribute(RecordType1 r[], int radix, PVector head, PVector tail)
/*  记录数组r中记录已按低位关键字key[i+1]，…，key[d]进行过"低位优先"排序。
本算法按第radix位关键字key[radix]建立RADIX个静态链表，同一个静态链表中记录的key[radix]相同。
head[j]和tail[j]分别指向各静态链表中第一个和最后一个记录（j=0，1，2，…，RADIX-1）。head[j]=0表示相应队列为空链表*/
{
    int j, p;

    for (j = 0; j <= RADIX - 1; ++j)
        tail[j] = head[j] = 0; /*  将RADIX个队列初始化为空链表 */
    p = r[0].next;             /*  p指向链表中的第一个记录 */
    while (p != 0)
    {
        j = Order(r[p].key[radix]); /* 用记录中第i位关键字求相应静态链表号 */
        if (head[j] == 0)
            head[j] = p; /* 将p所指向的结点加入第j个静态链表中 */
        else
            r[tail[j]].next = p;
        tail[j] = p;
        p = r[p].next;
    }
} /*  Distribute  */

static void Collect(RecordType1 r[], PVector head, PVector tail)
/* 本算法从0到RADIX-1 扫描各静态链表，将所有非空静态链表首尾相接，重新链接成一个链表 */
{
    int j, t;

    j = 0;
    while (head[j] == 0) /* 找第一个非空静态链表 */
        ++j;
    r[0].next = head[j];
    t = tail[j];
    while (j < RADIX - 1) /* 寻找并串接所有非空静态链表 */
    {
        ++j;
        while ((j < RADIX - 1) && (head[j] == 0)) /* 找下一个非空静态链表 */
            ++j;
        if (head[j] != 0) /* 链接非空静态链表 */
        {
            r[t].next = head[j];
            t = tail[j];
        }
    }
    r[t].next = 0; /* t指向最后一个非空链表中的最后一个结点 */
} /* Collect */

//将RecordType类型的序列转换称为RecordType1类型的序列
static RecordType1 *Initialize(RecordType r[], int length)
{
    RecordType1 *s;
    int i, j;
    KeyType k, max = r[1].key;

    //查找序列中最大值，以便确定需要分配和收集几趟。
    //例如：本例中键值的类型是uint16_t，最大可能值是65535，有5位数字，因此需要跑5趟。
    for (i = 2; i <= length; ++i)
        if (max < r[i].key)
            max = r[i].key;
    key_size = 0;
    while (max > 0)
    {
        ++key_size;
        max /= RADIX;
    }

    //提前将序列r中的每一个键值分解为各自权位上的数字，同时初始化静态链表。
    //例如：56281将被分解为：[万=>5, 千=>6, 百=>2, 十=>8, 个=>1]
    s = (RecordType1 *)malloc(sizeof(RecordType1) * (length + 1));
    for (i = 1; i <= length; ++i)
    {
        k = r[i].key;
        for (j = key_size - 1; j >= 0; --j)
        {
            //decompose k
            s[i].key[j] = k % 10;
            k /= 10;
        }
        s[i].next = i + 1; //初始化时，序列中的每一个元素的后继就是序列的自然直接后继。
    }
    s[0].next = 1;
    s[length].next = 0; //最后一个元素没有后继。0值相当于链表的末尾指针NULL。

    return s;
}

void RadixSort(RecordType r[], int length)
/* length个记录存放在数组r中，执行本算法进行基数排序后，链表中的记录将按关键字从小到大的顺序相链接。 */
{
    int i, j;
    PVector head; //head是个数组。数组元素head[i]是基数i的静态链表的“头指针”
    PVector tail; //tail是个数组。数组元素tail[i]是基数i的静态链表的“尾指针”

    RecordType1 *s = Initialize(r, length);

    for (i = key_size - 1; i >= 0; --i) /* 从最低位子关键字开始，进行key_size趟分配 和 收集*/
    {
        Distribute(s, i, head, tail); /* 第i趟分配 */
        Collect(s, head, tail);       /* 第i趟收集 */
    }

    //重置序列r，使之有序
    int p = s[0].next;
    for (i = 1; i <= length; ++i)
    {
        r[i].key = 0;
        for (j = 0; j < key_size; ++j)
            r[i].key = r[i].key * RADIX + s[p].key[j];
        p = s[p].next;
    }

    free(s);
} /* RadixSort  */