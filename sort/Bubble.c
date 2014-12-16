/*
 *  冒泡排序
 *  原理：将序列中小的值像气泡一样冒上来
 * */

#include "data.h"
#include "time.h"
extern a[LENGTH];

void Bubble(int a[]){
    for(int i=0;i<LENGTH-1;i++){
        for(int j=0;j<LENGTH-i-1;j++){
            if(a[j]>a[j+1]){
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
            }
        }
    }
}

//改进一：使用pos记录最后一次比较的位置
void Bubble_pos(int a[]){
    int i=LENGTH-1;
    while(i>0){
        int pos=0;
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
                pos=j;
            }
        }
        i=pos;
    }
}

//改进二：在一次排序中找到最大和最小值
void Bubble_dou(int a[]){
    int min=0;
    int max=LENGTH-1;
    int i;
    while(min<max){
        for(i=min;i<max;i++){
            if(a[i]>a[i+1]){
                a[i]=a[i]+a[i+1];
                a[i+1]=a[i]-a[i+1];
                a[i]=a[i]-a[i+1];
            }
        }
        min++;
        for(i=max;i>min;i--){
            if(a[i]<a[i-1]){
                a[i]=a[i]+a[i-1];
                a[i-1]=a[i]-a[i-1];
                a[i]=a[i]-a[i-1];
            }
        }
        max--;
    }
}

int main(int argc, char *argv[])
{
    clock_t start,end;
    start=clock();
    Bubble(a);
    end=clock();
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printSortArray(a,LENGTH);
    printf("简单冒泡所用时间%f秒\n",duration );
    return 0;
}
