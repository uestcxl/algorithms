/*
 *  选择排序
 *  原理：查找整个序列，找到最小的值，与第一个值交换；然后在剩下的序列中再找到最小的值与第二个值交换。。。。。
 *  实现：
 *      1.第一趟，从n个记录中找到最小的值，与第一个值交换
 *      2.第二趟，从n-1个记录中找到最小的值，与第二个值交换
 *      3.第三趟，从n-2个记录中找到最小的值，与第三个值交换
 *      .......
 *      i:第i趟，从第n-i+1个记录中找到最小的值，与第i个值交换
 * */

#include "data.h"
#include "time.h"
extern a[LENGTH];

void selectSort(int *a){
    int i,j,tmp;
    for(i=0;i<LENGTH-1;++i){
        tmp=i;
        for(j=i+1;j<LENGTH;++j){
            if(a[j]<a[tmp]){
                printf("\ni=%d,j=%d\n",i,j);
                tmp=j;
            }
        }
        if(a[tmp]!=a[i]){
            a[i]=a[i]+a[tmp];
            a[tmp]=a[i]-a[tmp];
            a[i]=a[i]-a[tmp];
        }
        printSortArray(a,i);
    }
}

/*
 *  二元选择排序
 *  原理：在一次循环中找出最大值与最小值，这样使得大循环次数减半
 * */
void DivSelectSort(int *a){
    int i,j,max,min;
    for(i=1;i<=LENGTH/2;++i){
        max=i;
        min=i;
        for(j=i+1;j<LENGTH-i;j++){
            if(a[j]<a[min]){
                min=j;
            }
            if(a[j]>a[max]){
                max=j;
                continue;
            }
        }
        a[i]=a[i]+a[min];
        a[min]=a[i]-a[min];
        a[i]=a[i]-a[min];
        a[LENGTH-i]=a[max]+a[LENGTH-i];
        a[max]=a[LENGTH-i]-a[max];
        a[LENGTH-i]=a[LENGTH-i]-a[max];
        printSortArray(a,i);
    }
}

int main(){
    clock_t start,end;
    printSortArray(a,0);
    start=clock();
    selectSort(a);
    //DivSelectSort(a);
    end=clock();
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printSortArray(a,LENGTH);
    printf("选择排序使用时间：%f\n",duration);
}
