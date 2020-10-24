#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define STACK_INIT_SIZE 10
#define STACkiNCREMENT 5

typedef int ElemType;

typedef struct SNode
{
    ElemType data;
    struct SNode *next;
} SNode,*SLink;

typedef struct
{
    SLink top;
    int length;
} LinkStack;

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

bool GetTop(LinkStack S,ElemType &e)
{
    if(StackEmpty(S))
        return false;
    e=S.top->data;
    return true;
}

bool Push(LinkStack &S,ElemType e)
{
    SLink p=(SLink)malloc(sizeof(SNode));
    p->data=e;
    p->next=S.top;
    S.top=p;
    S.length++;
    return true;
}

bool Pop(LinkStack &S,ElemType &e)
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
        printf("%d ",p->data);
        p=p->next;
    }
}


void createStack(LinkStack &S)
{
    int n=0;
    ElemType e;
    printf("size?");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("e?");
        scanf("%d",&e);
        Push(S,e);
    }
}

/**
n%2��ż�ж�
*/
/**�򵥶Գ����ִ�ƥ���㷨
    ��ȡ����b���˴������ִ���ͬ���ţ�   //���ŷ����ң�����Ǽ򵥶Գ����ִ�ƥ���㷨
    ���b��ջ��������ͬ�����ջ
    ����b��ջ
 */
bool MatchBrace(int *braces,int n)
{
    if(n<1||n%2!=0)//С��0����������
        return false;
    LinkStack S;
    InitStack(S);
    Push(S,braces[0]);
    int i=1;
    ElemType e;
    while(!StackEmpty(S)||i<n)
    {
        GetTop(S,e);
        if(braces[i]==e)
            Pop(S,e);
        else
            Push(S,braces[i]);
        i++;
    }
    if(StackEmpty(S))
        return true;
    return false;
}

int main()
{
    int b[]= {1,2,3,4,4,3,2,1};
    MatchBrace(b,8);
    return 0;
}
