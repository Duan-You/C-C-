#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

#define STACK_INIT_SIZE 10
#define STACkiNCREMENT 5

typedef BiTree SElemType;

typedef struct SNode
{
    SElemType data;
    struct SNode *next;
} SNode,*SLink;

typedef struct
{
    SLink top;
    int length;
} LinkStack;

void InitStack(LinkStack &S);

bool StackEmpty(LinkStack S);

int StackLength(LinkStack S);

bool GetTop(LinkStack S,SElemType &e);

bool Push(LinkStack &S,SElemType e);

bool Pop(LinkStack &S,SElemType &e);

void StackTraverse(LinkStack S);

void createStack(LinkStack &S);


#endif // __FUNC_H__
