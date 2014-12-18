/* 汉诺塔的递归 */
/* 函数参数：源柱子上的数量n,源柱子p1,辅助柱子p2,m目标柱子p3 */

#include "stdio.h"

void Hanoi(int n , int p1 , int p2 , int p3){
    if(n==1){
        printf("从%d到%d\n",p1,p3);
    }
    else{
        Hanoi(n-1,p1,p3,p2);
        printf("从%d到%d\n",p1,p3 );
        Hanoi(n-1,p2,p1,p3);
    }
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);
    Hanoi(n,1,2,3);
    return 0;
}
