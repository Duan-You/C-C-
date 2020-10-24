#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 2
#define LISTINCREMENT 3

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode,*LinkList;

void initList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}


void createListReverseOrder(LinkList &L)
{
    int n=0;
    LinkList p=NULL;
    ElemType e;
    printf("size?");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("e?");
        scanf("%d",&e);
        p=(LinkList)malloc(sizeof(LNode));
        p->data=e;
        p->next=L->next;
        L->next=p;
    }
}

void createListOrder(LinkList &L)
{
    int n=0;
    LinkList p=NULL,pre=L;
    ElemType e;
    printf("size?");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("e?");
        scanf("%d",&e);
        p=(LinkList)malloc(sizeof(LNode));
        p->data=e;
        p->next=NULL;
        pre->next=p;
        pre=p;
    }
}

bool GetElem(LinkList L,int i,ElemType &e)
{
    int j=1;
    LinkList p=L->next;
    while(p&&j<i)
    {
        j++;
        p=p->next;
    }
    if(!p||j>i)
        return false;
    e=p->data;
    return true;
}

int GetElemIndex(LinkList L,ElemType e)
{
    int i=1;
    LinkList p=L->next;
    while(p&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(!p)
        return 0;
    return i;
}

/**
LinkList p=L->next;
    while(L)
    {
        free(L);
        L=p;
        p=p->next;//错在空指针访问next域
    }
*/

void DestroyList(LinkList &L)
{
    LinkList p=L;
    while(p)
    {
        p=p->next;
        free(L);
        L=p;
    }
}

void ClearList(LinkList &L)
{
    LinkList p=L->next,r=p;
    while(r)
    {
        r=r->next;
        free(p);
        p=r;
    }
    L->next=NULL;
}

bool ListEmpty(LinkList L)
{
    if(L->next)
        return false;
    return true;
}

int ListLenth(LinkList L)
{
    int len=0;
    LinkList p=L->next;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

int compare(ElemType e1,ElemType e2)
{
    return e2-e1;
}

/** \brief 返回第一个和e满足compare条件的元素的位序，否则-1
 *
 * \param int (*compare)()比较判断函数
 * \param
 * \return
 *
 */

int LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType))
{
    int i=1;
    LinkList p=L->next;
    while(p)
    {
        if(compare(e,p->data)>0)
            return i;
        i++;
        p=p->next;
    }
    return 0;
}

bool PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
{
    LinkList pre=NULL,p=L->next;
    while(p&&p->data!=cur_e)
    {
        pre=p;
        p=p->next;
    }
    if(!p)
        return false;
    pre_e=pre->data;
    return true;
}

bool NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
{
    LinkList p=L->next;
    while(p&&p->data!=cur_e)
        p=p->next;
    if(!p)
        return false;
    next_e=p->next->data;
    return true;
}


bool ListInsert(LinkList &L,int i,ElemType e)
{
    if(i<1||i>ListLenth(L)+1)
        return false;
    LinkList p=L,pre=NULL;
    int j=0;
    while(p&&j<i)
    {
        pre=p;
        p=p->next;
        j++;
    }
    LinkList temp=(LinkList)malloc(sizeof(LNode));
    temp->data=e;
    pre->next=temp;
    temp->next=p;
    return true;
}

bool ListDelete(LinkList &L,int i,ElemType &e)
{

    if(i<1||i>ListLenth(L))
        return false;
    LinkList p=L,pre=NULL;
    int j=0;
    while(p&&j<i)
    {
        pre=p;
        p=p->next;
        j++;
    }
    pre->next=p->next;
    free(p);
    return true;
}

void visit(ElemType e)
{
    printf("%d ",e);
}

void traverse(LinkList L,void (*visit)(ElemType))
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
}

int main()
{
    LinkList L=NULL;
    initList(L);
    createListOrder(L);
    traverse(L,visit);
    ClearList(L);
    printf("%d",ListLenth(L));
}
