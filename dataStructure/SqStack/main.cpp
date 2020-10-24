#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 10
#define STACkiNCREMENT 5

typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
} SqStack;

void InitStack(SqStack &S)
{
    S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    S.top=S.base;
    S.stackSize=STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
    free(S.base);
    S.base=NULL;
    S.top=NULL;
    S.stackSize=0;
}

void ClearStack(SqStack &S)
{
    S.top=S.base;
}

bool StackEmpty(SqStack S)
{
    if(S.base==S.top)
        return true;
    return false;
}

int StackLength(SqStack S)
{
    return S.top-S.base;
}

bool GetTop(SqStack S,ElemType &e)
{
    if(StackEmpty(S))
        return false;
    e=*(S.top-1);
    return true;
}

bool Push(SqStack &S,ElemType e)
{
    if(S.top-S.base==S.stackSize)
    {//realloc :copy array
        S.base=(ElemType*)realloc(S.base,(S.stackSize+STACkiNCREMENT)*sizeof(ElemType));
        if(!S.base) exit(0);
        S.top=S.base+S.stackSize;//new base,updata top
        S.stackSize=S.stackSize+STACkiNCREMENT;
    }
    *S.top++=e;
    return true;
}

bool Pop(SqStack &S,ElemType &e)
{
    if(StackEmpty(S))
        return false;
    e=*--S.top;
    return true;
}

void StackTraverse(SqStack S)
{
    ElemType *p=S.base;
    while(p!=S.top)
    {
        printf("%d ",*p);
        p++;
    }
}


void createStack(SqStack &S)
{
    int n=0;
    ElemType e;
    printf("size?");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("e?");
        scanf("%d",&e);
        Push(S,e);
    }
}


int main()
{
    SqStack S;
    InitStack(S);
    createStack(S);
    ClearStack(S);
    StackTraverse(S);
    DestroyStack(S);
    return 0;
}
