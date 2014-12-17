/*
 *  插入排序--直接插入排序
 *  原理：将元素插入到一个有序序列中，序列元素总数加一。刚开始选择一个元素作为有序序列。
 *  要点：设置哨兵，记录数组边界；设置临时变量
 *  效率：O(n^2)
 *  其他插入排序：二分插入排序，2-路插入排序
 * */

#include "time.h"
#include "data.h"

extern a[10];

void InsertSort(int a[]){
    //共排序LENGTH-1次，首元素作为第一个有序序列
    for(int i=1;i<LENGTH;i++){
        //当值小于前一个值时，往前面的值插入。
        if(a[i] < a[i-1]){
            //设置当前值与待插入值（哨兵）
            int j=i-1;
            int data=a[i];
            //将前一个值后移至当前位置
            a[i]=a[i-1];
            //往前循环，直到待插入值大于等于j位置的值
            while(data < a[j] && j>=0){
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=data;
        }
        printSortArray(a,i);
    }
}

int main(){
    clock_t start,end;
    printSortArray(a,0);
    start=clock();
    InsertSort(a);
    end=clock();
    printSortArray(a,10);
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printf("排序使用时间：%f\n",duration);
    return 0;
}
