#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

int main()
{
    BiTree T;
    createBiTree2(T);
    preOrderTraverse2(T,visit);
    printf("\n");
    InOrderTraverse2(T,visit);
    printf("\n");
    postOrderTraverse2(T,visit);
    printf("\n");
    levelOrderTraverse(T,visit);
    return 0;
}
