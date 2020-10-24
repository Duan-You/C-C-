#include "BlockSearch.h"

/** \brief
 *
 建立的索引表要求按照关键字进行升序排序，查找表要么整体有序，要么分块有序。

分块有序指的是第二个子表中所有关键字都要大于第一个子表中的最大关键字，
第三个子表的所有关键字都要大于第二个子表中的最大关键字，依次类推。

块（子表）中各关键字的具体顺序，根据各自可能会被查找到的概率而定。
如果各关键字被查找到的概率是相等的，那么可以随机存放；
否则可按照被查找概率进行降序排序，以提高算法运行效率。
 *
 */


int BlockSearch(int a[],int n,int key)
{
    PIndex index;
    InitIndex(index,a,n);
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
            break;
        else if(a[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
}
