#include "include\ThreadTree.h"
using namespace std;

int main()
{
    ThreadTree T,pre=NULL;
    CreateThreadTree(T);
    InThread(T,pre);
    InOrderTraverse(T,visit);
    return 0;
}
