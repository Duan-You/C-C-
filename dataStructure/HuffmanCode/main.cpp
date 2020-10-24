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
    for(int i=1; i<=num; i++)//ÿ���ж�һ�Σ�ѭ���滻ȨֵС��
    {
        if(HT[i].parent==0)//δ���ϲ��Ľ��
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
            if(w1>w2&&w1>HT[i].weight)//��Ŀǰ�����滻Ϊ��ǰС��
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
    //��ʼ�����
    int child1,child2;
    for(i=n+1; i<=m; i++)
    {
        Select(HT,i-1,child1,child2);  //i-1=nʱ����ǰn���������Ȩֵ��С�������㣬i++ʹ��i=n+1
        HT[child1].parent=i;
        HT[child2].parent=i;
        HT[i].lchild=child1;
        HT[i].rchild=child2;
        HT[i].weight=HT[child1].weight+HT[child2].weight;
    }
    //����
    /*
    HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
    char *cd=(char*)malloc(n*sizeof(char));
    int temp,count;
    for(i=1;i<=n;i++)
    {
        count=0;
        //˫�׽�㲻Ϊ���ڵ㣻cָ��ǰ��㣬tempָ��˫�׽��
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
        //���򣬷�ת����
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
            HC[i]=(char*)malloc((n-star)*sizeof(char));//��1���ռ�
            strcpy(HC[i],&cd[star]);
        }
        free(cd);
    }
    /**

    ���ϵ����ַ������飬���ؽ�����


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
        cout<<c[j-1]<<" "<<HC[j]<<endl;//�˴��ƺ������������ַ��ı���ģ����abcd�ĸ��ַ�����Ӧ�ı���
    }
    return 0;
}
