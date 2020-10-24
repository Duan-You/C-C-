#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int ElemType;

typedef struct
{
    ElemType *base;
    int front,rear;
} SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.base=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    if(!Q.base)
        exit(0);
    Q.rear=0;
    Q.front=Q.rear;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

bool QueueEmpty(SqQueue Q)
{
    if(Q.front==Q.rear)
        return true;
    return false;
}

bool QueueFull(SqQueue Q)
{
    if((Q.rear+1)%MAXSIZE==Q.front)
        return true;
    return false;
}

bool EnQueue(SqQueue &Q,ElemType e)
{
    if((Q.rear+1)%MAXSIZE==Q.front)
        return false;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &e)
{
    if(Q.front==Q.rear)
        return false;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}

int main()
{
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    printf("%d ",Q.base[3]);
    ElemType e;
    DeQueue(Q,e);
    printf("%d ",e);
}
