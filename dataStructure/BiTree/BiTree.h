#ifndef __BITREE_H__
#define __BITREE_H__

#include <stdio.h>
#include <stdlib.h>
                    //'BiTree' does not name a type|�ݹ�ͷ�ļ�
typedef char ElemType;

typedef struct TNode
{
    ElemType data;
    struct TNode *lchild,*rchild;//�ṹ����ֻ���ǽṹ��ָ��
} TNode,*BiTree;

void createBiTree(BiTree &T);

void createBiTree2(BiTree &T);

void visit(ElemType e);

void preOrderTraverse(BiTree T,void (*visit)(ElemType e));

void InOrderTraverse(BiTree T,void (*visit)(ElemType e));

void postOrderTraverse(BiTree T,void (*visit)(ElemType e));

void levelOrderTraverse(BiTree T,void (*visit)(ElemType e));

void preOrderTraverse2(BiTree T,void (*visit)(ElemType e));

void InOrderTraverse2(BiTree T,void (*visit)(ElemType e));

void postOrderTraverse2(BiTree T,void (*visit)(ElemType e));

#endif // __FUNC_H__
