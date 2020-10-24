#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 2
#define LISTINCREMENT 3

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int lenth;
    int listSize;

} SqList;

void initList(SqList &L)
{
    L.data=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.data)
        return;
    L.lenth=0;
    L.listSize=LIST_INIT_SIZE;
}

void ListExpend(SqList &L)
{
    ElemType *data=(ElemType*)malloc((L.listSize+LISTINCREMENT)*sizeof(ElemType));
    for(int i=0; i<L.lenth; i++)
    {
        data[i]=L.data[i];
    }
    L.data=data;
    L.listSize=L.listSize+LISTINCREMENT;
    free(data);
}

void createList(SqList &L)
{
    int n=0;
    ElemType e;
    printf("size?");
    scanf("%d",&n);
    while(n>=L.listSize)
    {
        ListExpend(L);
    }
    for(int i=0; i<n; i++)
    {
        printf("e?");
        scanf("%d",&e);
        L.data[i]=e;
    }
    L.lenth=n;
}

bool GetElem(SqList L,int i,ElemType &e)
{
    if(i<0||i>=L.lenth)
        return false;
    e=L.data[i];
    return true;
}

int GetElemIndex(SqList L,ElemType e)
{
    for(int i=0; i<=L.lenth; i++)
    {
        if(L.data[i]==e)
            return i;
    }
    return -1;
}

void DestroyList(SqList &L)
{
    free(L.data);
}

void ClearList(SqList &L)
{
    L.lenth=0;
}

bool ListEmpty(SqList L)
{
    if(L.lenth==0)
        return true;
    return false;
}

int ListLenth(SqList L)
{
    return L.lenth;
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

int LocateElem(SqList L,ElemType e,int (*compare)(ElemType,ElemType))
{
    for(int i=0; i<L.lenth; i++)
    {
        if(compare(e,L.data[i])>0)
        {
            return i;
        }
    }
    return -1;
}

bool PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
{
    if(L.lenth<2||L.data[0]==cur_e)
        return false;
    pre_e=L.data[GetElemIndex(L,cur_e)-1];
    return true;
}

bool NextElem(SqList L,ElemType cur_e,ElemType &next_e)
{
    if(L.lenth<2||L.data[L.lenth-1]==cur_e)
        return false;
    next_e=L.data[GetElemIndex(L,cur_e)+1];
    return true;
}


bool ListInsert(SqList &L,int i,ElemType e)
{
    if(i<0||i>L.lenth)
        return false;
    if(L.listSize==L.lenth)
        ListExpend(L);
    for(int j=L.lenth-1; j>=i; j--)
    {
        L.data[j+1]=L.data[j];
    }
    L.data[i]=e;
    L.lenth++;
    return true;
}

bool ListDelete(SqList &L,int i,ElemType &e)
{
    if(i<0||i>L.lenth-1)
        return false;
    if(L.lenth==0)
        return false;
    for(int j=i+1; j<L.lenth; j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.lenth--;
    return true;
}

void visit(ElemType e)
{
    printf("%d ",e);
}

void traverse(SqList L,void (*visit)(ElemType))
{
    for(int i=0; i<L.lenth; i++)
    {
        visit(L.data[i]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    initList(L);
    createList(L);
    traverse(L,visit);
    ElemType e,e2;
    GetElem(L,2,e);
    printf("%d\n",e);
    int index=LocateElem(L,e,compare);
    printf("%d\n",index);

    PriorElem(L,e,e2);
    printf("%d\n",e2);
    NextElem(L,e,e2);
    printf("%d\n",e2);

    ListInsert(L,2,98);
    traverse(L,visit);

    ListDelete(L,2,e);
    traverse(L,visit);
    return 0;
}
