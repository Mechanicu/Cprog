#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "bstree.h"

#define RECURSIVE_

#ifdef RECURSIVE

BSTree BSTSearch(BSTree bst, KeyType key)
/*在根指针bst所指二叉排序树中，递归查找某关键字等于key的元素，若查找成功，返回指向该元素结点指针，否则返回空指针*/
{
    if (bst == NULL)
        return NULL;

    if (bst->key == key)
        return bst; /*查找成功*/
    else if (bst->key > key)
    	return BSTSearch(bst->lchild, key); /*在左子树继续查找*/
    else
    	return BSTSearch(bst->rchild, key); /*在右子树继续查找*/
}

#else

BSTree BSTSearch(BSTree bst, KeyType key)
/*在根指针bst所指二叉排序树bst上，查找关键字等于key的结点，若查找成功，返回指向该元素结点指针，否则返回空指针*/
{
    BSTree q = bst;

    while (q != NULL)
    {
        if (q->key == key)
            return q; /*查找成功*/
        if (q->key > key)
            q = q->lchild; /*在左子树中查找*/
        else
            q = q->rchild; /*在右子树中查找*/
    }
    return NULL; /*查找失败*/
} /*SearchBST*/

#endif

#ifndef AVLTREE

static void InsertTree(BSTree *bst, KeyType key)
/*若在二叉排序树中不存在关键字等于key的元素，插入该元素*/
{
    if (*bst == NULL) /*递归结束条件*/
    {
        BSTree s = (BSTree)malloc(sizeof(BSTNode)); /*申请新的结点s*/
        s->key = key;
        s->lchild = s->rchild = NULL;
        *bst = s;
    }
    else if (key < (*bst)->key)
        InsertTree(&((*bst)->lchild), key); /*将s插入左子树*/
    else if (key > (*bst)->key)
        InsertTree(&((*bst)->rchild), key); /*将s插入右子树*/
}

#else

static void InsertTree(AVLTree *avlt, KeyType K)
/*在平衡二叉树中插入元素k，使之成为一棵新的平衡二叉排序树*/
{
    // BSTNode *S;
    // BSTNode *A, *FA, *p, *fp, *B, *C;
    AVLTree S, A, FA, p, fp, B, C;

    S = (AVLTree)malloc(sizeof(AVLTNode));
    S->key = K;
    S->lchild = S->rchild = NULL;
    S->bf = 0;

    if (*avlt == NULL)
    {
        *avlt = S;
        return;
    }

    /* 首先查找S的插入位置fp，同时记录距S的插入位置最近且
    平衡因子不等于0（等于-1或1）的结点A，A为可能的失衡结点*/
    A = *avlt;
    FA = NULL;
    p = *avlt;
    fp = NULL;
    while (p != NULL)
    {
        if (p->key == K) //added by BZJ
        {
            free(S);
            return;
        } //end

        if (p->bf != 0)
        {
            A = p;
            FA = fp;
        }

        fp = p;
        if (K < p->key)
            p = p->lchild;
        else
            p = p->rchild;
    }

    /* 插入S*/
    if (K < fp->key)
        fp->lchild = S;
    else
        fp->rchild = S;

    /* 确定结点B，并修改A的平衡因子 */
    if (K < A->key)
    {
        B = A->lchild;
        A->bf = A->bf + 1;
    }
    else
    {
        B = A->rchild;
        A->bf = A->bf - 1;
    }

    /* 修改B到S路径上各结点的平衡因子（原值均为0）*/
    p = B;
    while (p != S)
        if (K < p->key)
        {
            p->bf = 1;
            p = p->lchild;
        }
        else
        {
            p->bf = -1;
            p = p->rchild;
        }

    /* 判断失衡类型并做相应处理 */
    if (A->bf == 2 && B->bf == 1) /* LL型 */
    {
        B = A->lchild;
        A->lchild = B->rchild;
        B->rchild = A;
        A->bf = 0;
        B->bf = 0;
        if (FA == NULL)
            *avlt = B;
        else if (A == FA->lchild)
            FA->lchild = B;
        else
            FA->rchild = B;
    }
    else if (A->bf == 2 && B->bf == -1) /* LR型 */
    {
        B = A->lchild;
        C = B->rchild;
        B->rchild = C->lchild;
        A->lchild = C->rchild;
        C->lchild = B;
        C->rchild = A;
        if (S->key < C->key)
        {
            A->bf = -1;
            B->bf = 0;
            C->bf = 0;
        }
        else if (S->key > C->key)
        {
            A->bf = 0;
            B->bf = 1;
            C->bf = 0;
        }
        else
        {
            A->bf = 0;
            B->bf = 0;
        }

        if (FA == NULL)
            *avlt = C;
        else if (A == FA->lchild)
            FA->lchild = C;
        else
            FA->rchild = C;
    }
    else if (A->bf == -2 && B->bf == 1) /* RL型 */
    {
        B = A->rchild;
        C = B->lchild;
        B->lchild = C->rchild;
        A->rchild = C->lchild;
        C->lchild = A;
        C->rchild = B;
        if (S->key < C->key)
        {
            A->bf = 0;
            B->bf = -1;
            C->bf = 0;
        }
        else if (S->key > C->key)
        {
            A->bf = 1;
            B->bf = 0;
            C->bf = 0;
        }
        else
        {
            A->bf = 0;
            B->bf = 0;
        }

        if (FA == NULL)
            *avlt = C;
        else if (A == FA->lchild)
            FA->lchild = C;
        else
            FA->rchild = C;
    }
    else if (A->bf == -2 && B->bf == -1) /* RR型 */
    {
        B = A->rchild;
        A->rchild = B->lchild;
        B->lchild = A;
        A->bf = 0;
        B->bf = 0;

        if (FA == NULL)
            *avlt = B;
        else if (A == FA->lchild)
            FA->lchild = B;
        else
            FA->rchild = B;
    }
}

#endif

void CreateFromFile(BSTree *bst)
{
    FILE *fp;
    KeyType len;
    const int size = sizeof(KeyType);

    fp = fopen(data_file, "rb");
    fread(&len, size, 1, fp);

    KeyType key;
    *bst = NULL; //very important!
    for (int i = 0; i < len; ++i)
    {
        fread(&key, size, 1, fp);
        InsertTree(bst, key);
    }
    fclose(fp);
}

void Destroy(BSTree *root)
{
    if (*root != NULL)
    {
        Destroy(&(*root)->lchild); /*后序遍历左子树*/
        Destroy(&(*root)->rchild); /*后序遍历右子树*/
        free(*root);               /*释放结点*/
    }
}

void Found(BSTree bst, KeyType key)
{
    if (bst != NULL)
        printf("--- Found key %d\n", key);
    else
        printf("--- Key %d was not found\n", key);
}