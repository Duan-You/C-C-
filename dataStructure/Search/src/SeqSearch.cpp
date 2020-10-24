#include "SeqSearch.h"

int SeqSearch(int a[],int n,int key)
{
    if(n<1)
        return 0;
    a[0]=key;
    int i=n-1;
    while(a[i]!=key)
        i--;
    return i;
}
