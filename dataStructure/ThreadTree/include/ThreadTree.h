#ifndef THREADTREE_H
#define THREADTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;

void CreateThreadTree(ThreadTree &T);

void InThread(ThreadTree &p,ThreadTree &pre);

void InOrderTraverse(ThreadTree &T,void (*visit)(ElemType e));

void visit(ElemType e);
#endif
