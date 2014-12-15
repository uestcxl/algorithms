/*
 *  希尔排序--缩小增量排序
 *  原理：把长的待排序的序列分割成若干个子序列分别进行插入排序，当序列基本有序时，再对整个序列直接插入排序
 *  要点：
 *      1.选择一个增量序列，t1,t2...tk，其中ti>tj
 *      2.按增量序列数k，对序列进行k次排序
 *      3.每趟排序，根据对应的增量ti，将待排序的序列分割为长度为m的子序列，分别对各个子表进行插排。
 *      (构造一个增量序列)
 * */

#include "data.h"
#include "time.h"
extern a[LENGTH];

void InsertSort(int a[],int dk){
    //共排序LENGTH-1次，首元素作为第一个有序序列
    for(int i=dk;i<LENGTH;i++){
        //当值小于前一个值时，往前面的值插入。
        if(a[i] < a[i-dk]){
            //设置当前值与待插入值（哨兵）
            int j=i-dk;
            int data=a[i];
            //将前一个值后移至当前位置
            a[i]=a[i-dk];
            //往前循环，直到待插入值大于等于j位置的值
            while(data < a[j]){
                a[j+dk]=a[j];
                j--;
            }
            a[j+dk]=data;
        }
        printSortArray(a,i);
    }
}

void shellSort(int a[],int n){
    int dk=n/2;
    while(dk>=1){
        InsertSort(a,dk);
        dk=dk/2;
    }
}

int main(){
    clock_t start,end;
    printSortArray(a,0);
    start=clock();
    shellSort(a,LENGTH);
    end=clock();
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printf("排序使用时间：%f\n",duration);
    return 0;
}
