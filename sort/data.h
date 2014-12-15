#ifndef _DATA_H_
#define _DATA_H_
#define LENGTH 10

#include "stdio.h"

int a[LENGTH]={20,30,100,60,1,50,2,90,50,44,60};

void printSortArray(int a[] , int num){
    printf("第%d次排序结果\n",num);
    for(int i=0;i<LENGTH;i++){
        printf("%d\t:%d\n",i+1,a[i]);
    }
}

#endif
