#include "BlockSearch.h"

/** \brief
 *
 ������������Ҫ���չؼ��ֽ����������򣬲��ұ�Ҫô��������Ҫô�ֿ�����

�ֿ�����ָ���ǵڶ����ӱ������йؼ��ֶ�Ҫ���ڵ�һ���ӱ��е����ؼ��֣�
�������ӱ�����йؼ��ֶ�Ҫ���ڵڶ����ӱ��е����ؼ��֣��������ơ�

�飨�ӱ��и��ؼ��ֵľ���˳�򣬸��ݸ��Կ��ܻᱻ���ҵ��ĸ��ʶ�����
������ؼ��ֱ����ҵ��ĸ�������ȵģ���ô���������ţ�
����ɰ��ձ����Ҹ��ʽ��н�������������㷨����Ч�ʡ�
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
