#ifndef BLOCKSEARCH_H
#define BLOCKSEARCH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Index
{
    int star;
    int maxKey;
}Index,*PIndex;

int BlockSearch(int a[],int n,int key);

void InitIndex(PIndex &index,int a[],int n);

#endif // BLOCKSEARCH_H
