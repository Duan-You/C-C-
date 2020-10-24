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
        if(p->lchild==NULL)//����Ϊ��ʱ��������ǰ��
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL)//�к���Ϊ��ʱ����Ҫ���ú�̽��
        {                               //preΪ�յ����Σ��ʼֱ�������ӣ���ֹ��ָ���ж�
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}

void InOrderTraverse(ThreadTree &T,void (*visit)(ElemType e))
{
    ThreadTree p=T;//��ǰ����Ϣ����ǰ����㣬���ɺ�̽���Һ��
    while(p)
    {
        while(p->ltag==0)//��������
            p=p->lchild;
        visit(p->data);
        while(p->rtag==1&&p->rchild)//����������̽��
        {
            p=p->rchild;
            visit(p->data);
        }
        p=p->rchild;//�Դ���̽����Ϣ
    }
}

void visit(ElemType e)
{
    printf("%c ",e);
}
