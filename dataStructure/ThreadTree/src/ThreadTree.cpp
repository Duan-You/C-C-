#include "ThreadTree.h"

void CreateThreadTree(ThreadTree &T)
{
    ElemType e;
    printf("e?");
    scanf("%c",&e);
    fflush(stdin);
    if(e==' ')
        T=NULL;
    else
    {
        T=(ThreadTree)malloc(sizeof(ThreadNode));
        if(!T)
            exit(0);
        T->data=e;
        T->ltag=0;
        T->rtag=0;
        CreateThreadTree(T->lchild);
        CreateThreadTree(T->rchild);
    }
}

void InThread(ThreadTree &p,ThreadTree &pre)
{
    if(p)
    {
        InThread(p->lchild,pre);
        if(p->lchild==NULL)//左孩子为空时，需设置前驱
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL)//有孩子为空时，需要设置后继结点
        {                               //pre为空的情形：最开始直到最左孩子，防止空指针判断
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}

void InOrderTraverse(ThreadTree &T,void (*visit)(ElemType e))
{
    ThreadTree p=T;//由前驱信息，到前驱结点，再由后继结点找后继
    while(p)
    {
        while(p->ltag==0)//到最左孩子
            p=p->lchild;
        visit(p->data);
        while(p->rtag==1&&p->rchild)//由线索到后继结点
        {
            p=p->rchild;
            visit(p->data);
        }
        p=p->rchild;//自带后继结点信息
    }
}

void visit(ElemType e)
{
    printf("%c ",e);
}
