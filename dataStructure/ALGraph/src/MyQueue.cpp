#include "myQueue.h"

void InitQueue(SqQueue &Q)
{
    Q.base=(QElemType*)malloc(MAXSIZE*sizeof(QElemType));
    if(!Q.base)
        exit(0);
    Q.rear=0;
    Q.front=Q.rear;
}

bool QueueEmpty(SqQueue Q)
{
    if(Q.front==Q.rear)
        return true;
    return false;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

bool QueueFull(SqQueue Q)
{
    if((Q.rear+1)%MAXSIZE==Q.front)
        return true;
    return false;
}

bool EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXSIZE==Q.front)
        return false;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear)
        return false;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}
