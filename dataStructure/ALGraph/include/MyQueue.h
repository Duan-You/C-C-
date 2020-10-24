#ifndef MYQUEUE_H
#define MYQUEUE_H


#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef char QElemType;

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

#endif // MYQUEUE_H
