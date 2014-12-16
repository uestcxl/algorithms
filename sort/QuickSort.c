/*
 *  快速排序：
 *  原理：通过一个基准元素，将记录分割成两块独立的部分，其中一块比基准值小，一块比基准值大；然后分别在两块中继续进行排序
 *  分治思想
 * */

#include "data.h"
#include "time.h"
extern a[LENGTH];

void swap(int *a , int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

//递归使用
void quickSort(int a[] , int low , int max){
    if(low<max){
        int mark=getMark(a,low,max);
        quickSort(a,low,mark-1);
        quickSort(a,mark+1,max);
    }
}

int getMark(int a[] , int low , int max){
    //选取头元素作为标记
    int sign=a[low];
    while(low<max){
        while(low<max && a[max]>=sign)
            max--;
        swap(&a[max],&a[low]);
        while(low<max && a[low]<=sign)
            low++;
        swap(&a[max],&a[low]);
    }
    printSortArray(a,LENGTH);
    //返回排好之后a[0]所在位置
    return low;
}

int main(int argc, char *argv[])
{
    clock_t start,end;
    start=clock();
    quickSort(a,0,LENGTH-1);
    end=clock();
    printSortArray(a,LENGTH);
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printf("快速排序所用时间%f\n",duration );
    return 0;
}
