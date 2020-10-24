#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

#define MAXSIZE 20

typedef BiTree QElemType;

typedef struct
{
    QElemType *base;
    int front,rear;
} SqQueue;

void InitQueue(SqQueue &Q);

int QueueLength(SqQueue Q);

bool QueueEmpty(SqQueue Q);

bool QueueFull(SqQueue Q);

bool EnQueue(SqQueue &Q,QElemType e);

bool DeQueue(SqQueue &Q,QElemType &e);

#endif // __FUNC_H__
