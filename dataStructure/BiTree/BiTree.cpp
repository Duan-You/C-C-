#include "BiTree.h"
#include "myStack.h"
#include "myQueue.h"

void createBiTree(BiTree &T)
{
    ElemType e;
    printf("e?");
    scanf("%c",&e);
    fflush(stdin);//不清空，就会读入回车，死循环
    if(e==' ')
        T=NULL;
    else
    {
        T=(BiTree)malloc(sizeof(TNode));
        if(!T)
            exit(0);
        T->data=e;//不需要初始化孩子节点指针
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}
/** \brief
  非递归先序创建二叉树
        建立树根，树根为空，直接结束函数
        栈不为空
            若左右孩子都不为空，则出栈
            若做孩子为空，则判断赋值
            若做孩子为空，则判断赋值
                        有孩子赋值空，则出栈
        循环操作，直到栈为空
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
        层序遍历
        若二叉树为空，结束
        树根入队列

        出队列，打印结点
        若孩子结点不为空入队列

        循环操作直到队列为空
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
        后序非递归遍历
        一直向左，入栈，直到做孩子空
        退回判断
                栈顶元素有孩子不为空，且未被访问，循环
                否则，出栈，访问，访问结点修改，循环条件设置
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
