#include "myStack.h"

void InitStack(LinkStack &S)
{
    S.top=NULL;
    S.length=0;
}

bool StackEmpty(LinkStack S)
{
    if(S.length==0)
        return true;
    return false;
}

int StackLength(LinkStack S)
{
    return S.length;
}

bool GetTop(LinkStack S,SElemType &e)
{
    if(StackEmpty(S))
        return false;
    e=S.top->data;
    return true;
}

bool Push(LinkStack &S,SElemType e)
{
    SLink p=(SLink)malloc(sizeof(SNode));
    p->data=e;
    p->next=S.top;
    S.top=p;
    S.length++;
    return true;
}

bool Pop(LinkStack &S,SElemType &e)
{
    if(StackEmpty(S))
        return false;
    e=S.top->data;
    SLink p=S.top;
    S.top=S.top->next;
    free(p);
    S.length--;
    return true;
}

void StackTraverse(LinkStack S)
{
    SLink p=S.top;
    while(p)
    {
        printf("%c ",p->data->data);
        p=p->next;
    }
}


void createStack(LinkStack &S)
{

}
