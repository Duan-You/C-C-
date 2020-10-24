#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct HNode
{
    int weight;
    int parent;
    int lchild,rchild;
} HNode,*HuffmanTree;

typedef char **HuffmanCode;

void Select(HuffmanTree &HT,int num,int &child1,int &child2)
{
    child1=0;
    child2=0;
    int w1=0;
    int w2=0;
    for(int i=1; i<=num; i++)//每次判断一次，循环替换权值小的
    {
        if(HT[i].parent==0)//未被合并的结点
        {
            if(child1==0)
            {
                child1=i;
                w1=HT[i].weight;
                continue;
            }
            if(child2==0)
            {
                child2=i;
                w2=HT[i].weight;
                continue;
            }
            if(w1>w2&&w1>HT[i].weight)//把目前最大的替换为当前小的
            {
                w1=HT[i].weight;
                child1=i;
                continue;
            }
            if(w2>w1&&w2>HT[i].weight)
            {
                w2=HT[i].weight;
                child2=i;
                continue;
            }
        }
    }
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{
    int m,i;
    m=2*n-1;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HNode));
    for(i=1; i<=n; i++,w++)
    {
        HT[i].lchild=0;
        HT[i].rchild=0;
        HT[i].parent=0;
        HT[i].weight=*w;
    }
    for(; i<=m; i++)
    {
        HT[i].lchild=0;
        HT[i].rchild=0;
        HT[i].parent=0;
        HT[i].weight=0;
    }
    //初始化完成
    int child1,child2;
    for(i=n+1; i<=m; i++)
    {
        Select(HT,i-1,child1,child2);  //i-1=n时代表前n个结点中找权值最小的两个点，i++使得i=n+1
        HT[child1].parent=i;
        HT[child2].parent=i;
        HT[i].lchild=child1;
        HT[i].rchild=child2;
        HT[i].weight=HT[child1].weight+HT[child2].weight;
    }
    //编码
    /*
    HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
    char *cd=(char*)malloc(n*sizeof(char));
    int temp,count;
    for(i=1;i<=n;i++)
    {
        count=0;
        //双亲结点不为根节点；c指向当前结点，temp指向双亲结点
        for(int c=i,temp=HT[i].parent;temp!=0;c=temp,temp=HT[temp].parent)
        {
            if(HT[temp].lchild==c)
            {
                cd[count++]='0';
            }
            else
            {
                cd[count++]='1';
            }
        }
        //倒序，反转数组
        HC[i]=(char*)malloc((count+1)*sizeof(char));
        for(int j=count-1;j>=0;j--)//j:count-1 ~ 0
        {
            HC[i][count-1-j]=cd[j];
        }
        HC[i][count]=0;
    }
    */

    HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
    char *cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';
    int star;
    for(int i=1;i<=n;i++)
    {
        star=n-1;
        for(int c=i,f=HT[c].parent;f!=0;c=f,f=HT[f].parent)
        {
            if(HT[f].lchild==c)
                cd[--star]='0';
            else
                cd[--star]='1';
            HC[i]=(char*)malloc((n-star)*sizeof(char));//多1个空间
            strcpy(HC[i],&cd[star]);
        }
        free(cd);
    }
    /**

    书上倒序建字符串数组，再重建数组


 */
}

int main()
{
    char c[]={'a','b','c','d','e'};
    HuffmanTree HT;
    HuffmanCode HC;
    int b[]={1,2,3,4,5};
    HuffmanCoding(HT,HC,b,5);
    for(int j=1;j<=5;j++)
    {
        cout<<c[j-1]<<" "<<HC[j]<<endl;//此处似乎是用来进行字符的编码的？输出abcd四个字符所对应的编码
    }
    return 0;
}
