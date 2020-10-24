#include "BiTree.h"
#include "myStack.h"
#include "myQueue.h"

void createBiTree(BiTree &T)
{
    ElemType e;
    printf("e?");
    scanf("%c",&e);
    fflush(stdin);//����գ��ͻ����س�����ѭ��
    if(e==' ')
        T=NULL;
    else
    {
        T=(BiTree)malloc(sizeof(TNode));
        if(!T)
            exit(0);
        T->data=e;//����Ҫ��ʼ�����ӽڵ�ָ��
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}
/** \brief
  �ǵݹ����򴴽�������
        ��������������Ϊ�գ�ֱ�ӽ�������
        ջ��Ϊ��
            �����Һ��Ӷ���Ϊ�գ����ջ
            ��������Ϊ�գ����жϸ�ֵ
            ��������Ϊ�գ����жϸ�ֵ
                        �к��Ӹ�ֵ�գ����ջ
        ѭ��������ֱ��ջΪ��
 */

void createBiTree2(BiTree &T)//waiting
{
    ElemType e;
    printf("e?");
    scanf("%c",&e);
    fflush(stdin);
    if(e==' ')
        return;
    T=(BiTree)malloc(sizeof(TNode));//
    T->data=e;
    T->lchild=NULL;
    T->rchild=NULL;
    LinkStack S;
    InitStack(S);
    Push(S,T);
    BiTree p,parent;
    bool leftFlag=true;
    while(!StackEmpty(S))//
    {
        GetTop(S,parent);
        if (parent->lchild==NULL&&leftFlag)
        {
            printf("e?");
            scanf("%c",&e);
            fflush(stdin);
            if(e!=' ')
            {
                p=(BiTree)malloc(sizeof(TNode));
                p->data=e;
                p->lchild=NULL;
                p->rchild=NULL;
                parent->lchild=p;
                Push(S,p);
            }
            else
            {
                parent->lchild=NULL;
                leftFlag=false;
            }
        }
        else
        {
            if(parent->rchild==NULL)
            {
                printf("e?");
                scanf("%c",&e);
                fflush(stdin);
                if(e!=' ')
                {
                    p=(BiTree)malloc(sizeof(TNode));
                    p->data=e;
                    p->lchild=NULL;
                    p->rchild=NULL;
                    parent->rchild=p;
                    Push(S,p);
                    leftFlag=true;
                }
                else
                {
                    parent->rchild=NULL;
                    Pop(S,p);
                }
            }
            else
            {
                Pop(S,p);
            }
        }//if NULL
    }
}

void visit(ElemType e)
{
    printf("%c ",e);
}

void preOrderTraverse(BiTree T,void (*visit)(ElemType e))
{
    if(!T)
        return;
    visit(T->data);
    preOrderTraverse(T->lchild,visit);
    preOrderTraverse(T->rchild,visit);
}

void InOrderTraverse(BiTree T,void (*visit)(ElemType e))
{
    if(!T)
        return;
    InOrderTraverse(T->lchild,visit);
    visit(T->data);
    InOrderTraverse(T->rchild,visit);
}

void postOrderTraverse(BiTree T,void (*visit)(ElemType e))
{
    if(!T)
        return;
    postOrderTraverse(T->lchild,visit);
    postOrderTraverse(T->rchild,visit);
    visit(T->data);
}
/** \brief
        �������
        ��������Ϊ�գ�����
        ���������

        �����У���ӡ���
        �����ӽ�㲻Ϊ�������

        ѭ������ֱ������Ϊ��
 */

void levelOrderTraverse(BiTree T,void (*visit)(ElemType e))
{
    if(T==NULL)
        return;
    SqQueue Q;
    InitQueue(Q);
    BiTree t=T;
    EnQueue(Q,t);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q,t);
        visit(t->data);
        if(t->lchild)

            EnQueue(Q,t->lchild);
        if(t->rchild)
            EnQueue(Q,t->rchild);
    }
}

void preOrderTraverse2(BiTree T,void (*visit)(ElemType e))
{
    if(!T)
        return;
    LinkStack S;
    InitStack(S);
    BiTree p=T;
    while(p||!StackEmpty(S))
    {
        if(p)
        {
            visit(p->data);
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            Pop(S,p);
            p=p->rchild;
        }
    }
}

void InOrderTraverse2(BiTree T,void (*visit)(ElemType e))
{
    if(!T)
        return;
    LinkStack S;
    InitStack(S);
    BiTree p=T;
    while(p||!StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            Pop(S,p);
            visit(p->data);
            p=p->rchild;
        }
    }
}
/** \brief
        ����ǵݹ����
        һֱ������ջ��ֱ�������ӿ�
        �˻��ж�
                ջ��Ԫ���к��Ӳ�Ϊ�գ���δ�����ʣ�ѭ��
                ���򣬳�ջ�����ʣ����ʽ���޸ģ�ѭ����������
 */

void postOrderTraverse2(BiTree T,void (*visit)(ElemType e))
{
    if(!T)
        return;
    LinkStack S;
    InitStack(S);
    BiTree p=T,pre=NULL;
    while(p||!StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            GetTop(S,p);
            if(p->rchild&&p->rchild!=pre)
                p=p->rchild;
            else
            {
                Pop(S,p);
                visit(p->data);
                pre=p;
                p=NULL;
            }
        }
    }
}
