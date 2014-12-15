#include "stdio.h"
#include "time.h"
#include "avl.c"

int main(){
    int i,j;
    struct AVLTree* pRoot=NULL;

    srand((unsigned int)time(NULL));

    for(i=0;i<10;i++){
        j=rand();
        printf("%d\n",j);
        pRoot=insert_tree(j,pRoot);
    }

    print_tree(pRoot);

    delete_tree(&pRoot);

    return 0;
}
