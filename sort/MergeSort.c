/*
 *  归并排序
 *  原理：先把序列分为几个块，块内有序，块间无序，再将各个块归并
 *  实现：每个单独元素必然是有序的，先把N个元素的序列看成N个子序列，进行归并排序之后成为n/2或者n/2+1个子序列，再进行
 *      两两合并，直到全部合并
 * */

#include "data.h"
#include "time.h"

/*  @params a[]:待排序数组
 *  @params b[]:辅助存放结果的数组
*   两个序列为a[i,...,m]和a[m+1,...n]
 * */
void Merge(int a[] , int b[] , int i , int m , int n){
    int j,k;
    for(j=m+1,k=i;i<=m & j<=n;k++){
        if(a[j]<a[i]){
            b[k]=a[j++];
        }
        else
            b[k]=a[i++];
    }
    while(i<m)  b[k++]=a[i++];
    while(j<n)  b[k++]=a[j++];
}

void MergeSort(int a[] , int b[]){
    int length=1;
    int *p=a;
    int *tmp;
    while(length<LENGTH){
        int len=length;
        length=2*len;
        int i=0;
        while(i+length<LENGTH){
            Merge(p,b,i,i+len-1,i+length-1);
            i=i+length;
        }
        if(i+length<LENGTH){
            Merge(p,b,i,i+len-1,LENGTH-1);
        }
        tmp=b;  b=p;    p=tmp;
    }
}

int main(int argc, char *argv[])
{
    clock_t start,end;
    int b[10];
    start=clock();
    MergeSort(a,b);
    end=clock();
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printSortArray(a,LENGTH);
    printSortArray(b,LENGTH);
    printf("归并排序所用时间为%f\n",duration );
    return 0;
}
