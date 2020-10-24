#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "include\MyQueue.h"
using namespace std;
#define MAX_VERTEX_NUM 20

typedef char VertexType;

typedef struct ArcNode
{
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;
    int kind;
} ALGraph;

int LocateVex(ALGraph G,VertexType u)
{
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data==u)
            return i;
    }
    return -1;
}

/**
    先初始化
    顶点
    边
*/
void CreateUDG(ALGraph &G)
{
    int i;
    printf("顶点数和边数\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for( i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        printf("顶点\n");
        scanf("%c",&G.vertices[i].data);
        G.vertices[i].firstarc=NULL;
    }
    VertexType u1,u2;
    int index1,index2;
    ArcNode *p;
    for( i=0; i<G.arcnum; i++)
    {
        do
        {
            printf("一对邻接顶点\n");
            fflush(stdin);
            scanf("%c %c",&u1,&u2);
            index1=LocateVex(G,u1);
            index2=LocateVex(G,u2);
        }
        while(index1==-1||index2==-1);
        p=(ArcNode*)malloc(sizeof(ArcNode));//倒序插入边
        if(!p)
            exit(0);
        p->adjvex=index2;
        p->nextarc=G.vertices[index1].firstarc;
        G.vertices[index1].firstarc=p;
        p=(ArcNode*)malloc(sizeof(ArcNode));//无向图，边重复
        if(!p)
            exit(0);
        p->adjvex=index1;
        p->nextarc=G.vertices[index2].firstarc;
        G.vertices[index2].firstarc=p;
    }
}

void CreateDG(ALGraph &G)
{
    int i;
    printf("顶点数和边数\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for( i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        printf("顶点\n");
        scanf("%c",&G.vertices[i].data);
        G.vertices[i].firstarc=NULL;
    }
    VertexType u1,u2;
    int index1,index2;
    ArcNode *p;
    for( i=0; i<G.arcnum; i++)
    {
        do
        {
            printf("一对邻接顶点\n");
            fflush(stdin);
            scanf("%c %c",&u1,&u2);
            index1=LocateVex(G,u1);
            index2=LocateVex(G,u2);
        }
        while(index1==-1||index2==-1);
        p=(ArcNode*)malloc(sizeof(ArcNode));//倒序插入边
        if(!p)
            exit(0);
        p->adjvex=index2;
        p->nextarc=G.vertices[index1].firstarc;
        G.vertices[index1].firstarc=p;
    }
}

void CreateDN(ALGraph &G)
{
    int i;
    printf("顶点数和边数\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for( i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        printf("顶点\n");
        scanf("%c",&G.vertices[i].data);
        G.vertices[i].firstarc=NULL;
    }
    VertexType u1,u2;
    int index1,index2;
    ArcNode *p;
    int w;
    for( i=0; i<G.arcnum; i++)
    {
        do
        {
            printf("一对邻接顶点\n");
            fflush(stdin);
            scanf("%c %c %d",&u1,&u2,&w);
            index1=LocateVex(G,u1);
            index2=LocateVex(G,u2);
        }
        while(index1==-1||index2==-1);
        p=(ArcNode*)malloc(sizeof(ArcNode));//倒序插入边
        if(!p)
            exit(0);
        p->adjvex=index2;
        p->weight=w;
        p->nextarc=G.vertices[index1].firstarc;
        G.vertices[index1].firstarc=p;
    }
}

void CreateUDN(ALGraph &G)
{
    int i;
    printf("顶点数和边数\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for( i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        printf("顶点\n");
        scanf("%c",&G.vertices[i].data);
        G.vertices[i].firstarc=NULL;
    }
    VertexType u1,u2;
    int index1,index2;
    ArcNode *p;
    int w;
    for( i=0; i<G.arcnum; i++)
    {
        do
        {
            printf("一对邻接顶点\n");
            fflush(stdin);
            scanf("%c %c %d",&u1,&u2,&w);
            index1=LocateVex(G,u1);
            index2=LocateVex(G,u2);
        }
        while(index1==-1||index2==-1);
        p=(ArcNode*)malloc(sizeof(ArcNode));//倒序插入边
        if(!p)
            exit(0);
        p->adjvex=index2;
        p->weight=w;
        p->nextarc=G.vertices[index1].firstarc;
        G.vertices[index1].firstarc=p;
        p=(ArcNode*)malloc(sizeof(ArcNode));//倒序插入边
        if(!p)
            exit(0);
        p->adjvex=index1;
        p->weight=w;
        p->nextarc=G.vertices[index2].firstarc;
        G.vertices[index2].firstarc=p;
    }
}


void CreateGraph(ALGraph &G)
{
    printf("输入图的类型：\n");
    scanf("%d",&G.kind);
    switch(G.kind)
    {
    case 0:
        CreateDG(G);
        break;
    case 1:
        CreateDN(G);
        break;
    case 2:
        CreateUDG(G);
        break;
    case 3:
        CreateUDN(G);
        break;
    default:
        printf("error\n");
    }
}

/** \brief
    销毁边的结点
 */

void DestroyGraph(ALGraph &G)
{
    ArcNode *p;
    for(int i=0; i<G.vexnum; i++)
    {
        p=G.vertices[i].firstarc;
        while(G.vertices[i].firstarc)//p&G.vertices[i].firstarc同步，不会出现空指针访问域
        {
            p=p->nextarc;
            free(G.vertices[i].firstarc);
            G.vertices[i].firstarc=p;
        }
        G.vertices[i].firstarc=NULL;
    }
}

VertexType GetVex(ALGraph G,VertexType u)
{
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data==u)
            return u;
    }
    return NULL;
}

bool PutVex(ALGraph &G,VertexType v,VertexType value)
{
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data==v)
        {
            G.vertices[i].data=value;
            return true;
        }
    }
    return false;
}

int FirstAdjVex(ALGraph G,VertexType v)
{
    int index=LocateVex(G,v);
    if(G.vertices[index].firstarc)
        return G.vertices[index].firstarc->adjvex;
    return -1;
}

int NextAdjVex(ALGraph G,VertexType v,VertexType w)
{
    int index1=LocateVex(G,v);
    int index2=LocateVex(G,w);
    ArcNode *p=G.vertices[index1].firstarc;
    while(p)
    {
        if(p->adjvex==index2)
            break;
        p=p->nextarc;
    }
    if(p&&p->nextarc)
        return p->nextarc->adjvex;
    return -1;
}

bool InsertVex(ALGraph &G,VertexType v)
{
    int index = LocateVex(G,v);
    if(index!=-1||G.vexnum>=MAX_VERTEX_NUM)
        return false;
    G.vertices[G.vexnum].data=v;
    G.vertices[G.vexnum++].firstarc=NULL;
    return true;
}

bool InsertArc(ALGraph &G,VertexType v,VertexType v2,int w)
{
    int index1=LocateVex(G,v);
    int index2=LocateVex(G,v2);
    if(index1==-1||index2==-1)
        return false;
    ArcNode *p;
    switch(G.kind)
    {
    case 0://DG
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=index2;
        p->nextarc=G.vertices[index1].firstarc;
        G.vertices[index1].firstarc=p;
        break;
    case 1://DN
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=index2;
        p->weight=w;
        p->nextarc=G.vertices[index1].firstarc;
        G.vertices[index1].firstarc=p;
        break;
    case 2://UDG
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=index2;
        p->nextarc=G.vertices[index1].firstarc;
        G.vertices[index1].firstarc=p;
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=index1;
        p->nextarc=G.vertices[index2].firstarc;
        G.vertices[index2].firstarc=p;
        break;
    case 3:
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=index2;
        p->weight=w;
        p->nextarc=G.vertices[index1].firstarc;
        G.vertices[index1].firstarc=p;
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=index1;
        p->weight=w;
        p->nextarc=G.vertices[index2].firstarc;
        G.vertices[index2].firstarc=p;
        break;
    default:
        printf("error\n");
    }
    G.arcnum++;
    return true;
}

bool DeleteArc(ALGraph &G,VertexType v,VertexType w)
{
    int index1=LocateVex(G,v);
    int index2=LocateVex(G,w);
    if(index1==-1||index2==-1)
        return false;
    ArcNode *p,*pre=NULL;
    switch(G.kind)
    {
    case 0:;//DG
    case 1://DN
        p=G.vertices[index1].firstarc;
        while(p&&p->adjvex!=index2)
        {
            pre=p;
            p=p->nextarc;
        }
        if(!p)
            return false;
        if(pre==NULL)
            G.vertices[index1].firstarc=NULL;
        else
            pre=p->nextarc;
        free(p);
        break;
    case 2:;//UDG
    case 3:
        p=G.vertices[index1].firstarc;
        while(p&&p->adjvex!=index2)
        {
            pre=p;
            p=p->nextarc;
        }
        if(!p)
            return false;
        if(pre==NULL)
            G.vertices[index1].firstarc=NULL;
        else
            pre=p->nextarc;
        free(p);
        p=G.vertices[index2].firstarc;
        while(p&&p->adjvex!=index1)
        {
            pre=p;
            p=p->nextarc;
        }
        if(!p)
            return false;
        if(pre==NULL)
            G.vertices[index1].firstarc=NULL;
        else
            pre=p->nextarc;
        free(p);
        break;
    default:
        printf("error\n");
    }
    G.arcnum--;
    return true;
}

bool DeleteVex(ALGraph &G,VertexType v)
{
    if(G.vexnum==1)
        return false;
    int indexV=LocateVex(G,v);
    if(indexV==-1)
        return false;
    //删边
    ArcNode *p=G.vertices[indexV].firstarc;
    while(G.vertices[indexV].firstarc)
    {
        p=p->nextarc;
        free(G.vertices[indexV].firstarc);
        G.vertices[indexV].firstarc=p;
    }
    G.vertices[indexV].firstarc=NULL;
    //删相关边
    for(int i=0; i<G.vexnum; i++)
    {
        DeleteArc(G,G.vertices[i].data,v);
    }
    //删顶点
    for(int i=indexV; i<G.vexnum-1; i++)
    {
        G.vertices[indexV].data=G.vertices[indexV+1].data;
    }
    G.vexnum--;
    return true;
}



void visit(VertexType v)
{
    printf("%c ",v);
}




bool visited[MAX_VERTEX_NUM];
void (*visitFunc)(VertexType v);

void DFS(ALGraph G,int v)
{
    visitFunc(G.vertices[v].data);
    visited[v]=true;
    for(int w=FirstAdjVex(G,G.vertices[v].data); w>=0; w=NextAdjVex(G,G.vertices[v].data,G.vertices[w].data))
    {
        if(!visited[w])
            DFS(G,w);
    }
}

void DFSTraverse(ALGraph G,void (*visit)(VertexType v))
{
    visitFunc=visit;
    for(int i=0; i<G.vexnum; i++)
        visited[i]=false;
    for(int i=0; i<G.vexnum; i++)
    {
        if(!visited[i])
            DFS(G,i);
    }
}

void BFSTraverse(ALGraph G,void (*visit)(VertexType v))
{
    for(int i=0; i<G.vexnum; i++)
        visited[i]=false;
    SqQueue Q;
    InitQueue(Q);
    char temp;
    for(int i=0; i<G.vexnum; i++)
    {
        if(!visited[i])
        {
            visit(G.vertices[i].data);
            visited[i]=true;
            EnQueue(Q,G.vertices[i].data);
            while(!QueueEmpty(Q))
            {
                DeQueue(Q,temp);
                for(int w=FirstAdjVex(G,temp); w>=0; w=NextAdjVex(G,temp,G.vertices[w].data))
                {
                    if(!visited[w])
                    {
                        visit(G.vertices[w].data);
                        visited[w]=true;
                        EnQueue(Q,G.vertices[w].data);
                    }
                }
            }
        }//if
    }
}


int main()
{
    ALGraph G;
    CreateGraph(G);
    InsertVex(G,'g');
    InsertArc(G,'a','g',2);
    BFSTraverse(G,visit);
    cout<<endl;
    DFSTraverse(G,visit);
    DeleteVex(G,'g');
    BFSTraverse(G,visit);
    cout<<endl;
    DFSTraverse(G,visit);
    return 0;
}
