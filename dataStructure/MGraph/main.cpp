#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "include\MyQueue.h"
using namespace std;

#define INFINITY INT_MAX
#define MaxVertexNum 20

typedef enum
{
    DG,DN,UDG,UDN
} GraphKind;

typedef char VertexType;
typedef int VRType;
typedef char InfoType;

typedef struct ArcCell
{
    VRType adj;
    InfoType *info;
} ArcCell,AdjMatrix[MaxVertexNum][MaxVertexNum];

typedef struct
{
    VertexType vexs[MaxVertexNum];
    AdjMatrix arcs;
    int vexnum,arcnum;
    GraphKind kind;
} MGraph;

int LocateVex(MGraph G,VertexType u)
{
    if(u==NULL)
        return -1;
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vexs[i]==u)
            return i;
    }
    return -1;
}

/**
    先初始化
    顶点
    边
*/
void CreateUDG(MGraph &G)
{
    G.kind=UDG;
    int i,j;
    printf("顶点数和边数\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for( i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        printf("顶点\n");
        scanf("%c",&G.vexs[i]);
    }
    for( i=0; i<G.vexnum; i++)
        for( j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j].adj=0;
            G.arcs[i][j].info=NULL;
        }
    VertexType u1,u2;
    int index1,index2;
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
        G.arcs[index1][index2].adj=1;
        G.arcs[index2][index1].adj=1;
    }
}

void CreateDG(MGraph &G)
{
    G.kind=DG;
    int i,j;
    printf("顶点数和边数\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for( i=0; i<G.vexnum; i++)
    {
        printf("顶点\n");
        fflush(stdin);
        scanf("%c",&G.vexs[i]);
    }
    for( i=0; i<G.vexnum; i++)
        for( j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j].adj=0;
            G.arcs[i][j].info=NULL;
        }
    VertexType u1,u2;
    int index1,index2;
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
        G.arcs[index1][index2].adj=1;
    }
}

void CreateDN(MGraph &G)
{
    G.kind=DN;
    int i,j;
    printf("顶点数和边数\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for( i=0; i<G.vexnum; i++)
    {
        printf("顶点\n");
        fflush(stdin);
        scanf("%c",&G.vexs[i]);
    }
    for( i=0; i<G.vexnum; i++)
        for( j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j].adj=INFINITY;
            G.arcs[i][j].info=NULL;
        }
    VertexType u1,u2;
    int index1,index2;
    VRType w;
    for( i=0; i<G.arcnum; i++)
    {
        do
        {
            printf("一对邻接顶点及权值\n");
            fflush(stdin);
            scanf("%c %c %d",&u1,&u2,&w);
            index1=LocateVex(G,u1);
            index2=LocateVex(G,u2);
        }
        while(index1==-1||index2==-1);
        G.arcs[index1][index2].adj=w;
    }
}

void CreateUDN(MGraph &G)
{
    G.kind=UDN;
    int i,j;
    printf("顶点数和边数\n");
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for( i=0; i<G.vexnum; i++)
    {
        printf("顶点\n");
        fflush(stdin);
        scanf("%c",&G.vexs[i]);
    }
    for( i=0; i<G.vexnum; i++)
        for( j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j].adj=INFINITY;
            G.arcs[i][j].info=NULL;
        }
    VertexType u1,u2;
    int index1,index2;
    VRType w;
    for( i=0; i<G.arcnum; i++)
    {
        do
        {
            printf("一对邻接顶点及权值\n");
            fflush(stdin);
            scanf("%c %c %d",&u1,&u2,&w);
            index1=LocateVex(G,u1);
            index2=LocateVex(G,u2);
        }
        while(index1==-1||index2==-1);
        G.arcs[index1][index2].adj=w;
        G.arcs[index2][index1].adj=w;
    }
}


void CreateGraph(MGraph &G)
{
    printf("输入图的类型：\n");
    scanf("%d",&G.kind);
    switch(G.kind)
    {
    case DG:
        CreateDG(G);
        break;
    case DN:
        CreateDN(G);
        break;
    case UDG:
        CreateUDG(G);
        break;
    case UDN:
        CreateUDN(G);
        break;
    default:
        printf("error\n");
    }
}


void DestroyGraph(MGraph &G)
{

}

VertexType GetVex(MGraph G,VertexType u)
{
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vexs[i]==u)
            return u;
    }
    return NULL;
}

bool PutVex(MGraph &G,VertexType v,VertexType value)
{
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vexs[i]==v)
        {
            G.vexs[i]=value;
            return true;
        }
    }
    return false;
}

VertexType FirstAdjVex(MGraph G,VertexType v)
{
    int index=LocateVex(G,v);
    if(index==-1)
        return NULL;
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.arcs[index][i].adj!=0&&G.arcs[index][i].adj!=INFINITY)
            return G.vexs[i];
    }
    return NULL;
}

VertexType NextAdjVex(MGraph G,VertexType v,VertexType w)
{
    int index=LocateVex(G,v);
    int adjIndex=LocateVex(G,w);
    if(index==-1||adjIndex==-1)
        return NULL;
    for(int i=index+1; i<G.vexnum; i++)
        for(int j=adjIndex+1; j<G.vexnum; j++)
        {
            if(G.arcs[i][j].adj!=0&&G.arcs[index][i].adj!=INFINITY)
                return G.vexs[j];
        }
    return NULL;
}

bool InsertVex(MGraph &G,VertexType v)
{
    if(LocateVex(G,v)!=-1||G.vexnum>=MaxVertexNum)
        return false;
    G.vexs[G.vexnum++]=v;
    if(G.kind==DG||G.kind==UDG)
    {
        for(int i=0; i<G.vexnum; i++)
        {
            G.arcs[G.vexnum-1][i].adj=0;
            G.arcs[i][G.vexnum-1].adj=0;
        }
    }
    else
    {
        for(int i=0; i<G.vexnum; i++)
        {
            G.arcs[G.vexnum-1][i].adj=INFINITY;
            G.arcs[i][G.vexnum-1].adj=INFINITY;
        }
    }
    return true;
}

bool DeleteVex(MGraph &G,VertexType v)
{
    int index=LocateVex(G,v);
    if(index==-1)
        return false;
    if(index==0)//不允许图为空   在图中，不允许没有顶点。若 V 是图的顶点的集合，那么，V 是非空有穷集合。
        return false;
    for(int i=index; i<G.vexnum-1; i++)
    {
        G.vexs[index]=G.vexs[index+1];
    }
    G.vexnum--;
    return true;
}

bool InsertArc(MGraph &G,VertexType v,VertexType v2,VRType w)
{
    int indexV1=LocateVex(G,v);
    int indexV2=LocateVex(G,v2);
    if(indexV1==-1||indexV2==-1)
        return false;
    if((G.kind==DG||G.kind==UDG)&&G.arcs[indexV1][indexV2].adj!=0)
        return false;
    if((G.kind==DN||G.kind==UDN)&&G.arcs[indexV1][indexV2].adj!=INFINITY)
        return false;
    switch(G.kind)
    {
    case DG:
        G.arcs[indexV1][indexV2].adj=1;
        break;
    case DN:
        G.arcs[indexV1][indexV2].adj=w;
        break;
    case UDG:
        G.arcs[indexV1][indexV2].adj=1;
        G.arcs[indexV2][indexV1].adj=1;
        break;
    case UDN:
        G.arcs[indexV1][indexV2].adj=w;
        G.arcs[indexV2][indexV1].adj=w;
        break;
    default:
        printf("error\n");
    }
    G.arcnum++;
    return true;
}

bool DeleteArc(MGraph &G,VertexType v,VertexType w)
{
    int indexV1=LocateVex(G,v);
    int indexV2=LocateVex(G,w);
    if(indexV1==-1||indexV2==-1)
        return false;
    switch(G.kind)
    {
    case DG:
        G.arcs[indexV1][indexV2].adj=0;
        break;
    case DN:
        G.arcs[indexV1][indexV2].adj=INFINITY;
        break;
    case UDG:
        G.arcs[indexV1][indexV2].adj=0;
        G.arcs[indexV2][indexV1].adj=0;
        break;
    case UDN:
        G.arcs[indexV1][indexV2].adj=INFINITY;
        G.arcs[indexV2][indexV1].adj=INFINITY;
        break;
    default:
        printf("error\n");
    }
    G.arcnum--;
    return true;
}

void visit(VertexType v)
{
    printf("%c ",v);
}

bool visited[MaxVertexNum];
void (*visitFunc)(VertexType v);

void DFS(MGraph G,int v)
{
    visited[v]=true;
    visitFunc(G.vexs[v]);
    for(int w=LocateVex(G,FirstAdjVex(G,G.vexs[v])); w>=0; w=LocateVex(G,NextAdjVex(G,G.vexs[v],w)))
    {
        if(!visited[w])
            DFS(G,w);
    }
}

void DFSTraverse(MGraph G,void (*visit)(VertexType v))
{
    visitFunc=visit;
    for(int v=0; v<G.vexnum; v++)
        visited[v]=false;
    for(int v=0; v<G.vexnum; v++)
    {
        if(!visited[v])
            DFS(G,v);
    }
}

void BFSTraverse(MGraph G,void (*visit)(VertexType v))
{
    for(int v=0; v<G.vexnum; v++)
        visited[v]=false;
    SqQueue Q;
    InitQueue(Q);
    for(int v=0; v<G.vexnum; v++)
    {
        if(!visited[v])
        {
            visited[v]=true;
            visit(G.vexs[v]);
            EnQueue(Q,G.vexs[v]);
            char temp;
            while(!QueueEmpty(Q))
            {
                DeQueue(Q,temp);
                for(int w=LocateVex(G,FirstAdjVex(G,temp)); w>=0; w=LocateVex(G,NextAdjVex(G,temp,w)))
                {
                    if(!visited[w])
                    {
                        visited[w]=true;
                        visit(G.vexs[w]);
                        EnQueue(Q,G.vexs[w]);
                    }
                }
            }//while
        }
    }//for
}

int main()
{
    MGraph G;
    CreateGraph(G);
    BFSTraverse(G,visit);
    return 0;
}
