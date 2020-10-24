#include "BinarySearch.h"

int BinarySearch(int *a,int n,int key)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
