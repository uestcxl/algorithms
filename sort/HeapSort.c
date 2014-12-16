/*
 *  选择排序--堆排序
 *  原理：建立小(大)顶堆，堆对应的是一颗完全二叉树，所有非叶子结点不大(小)于其子女的值，因此，堆顶元素是最小(大)的
 *      取出堆顶元素，再对剩余的元素进行堆排序，直到排序完成。
 *  复杂度：O(nlogn)
 * */

#include "data.h"
#include "time.h"
extern a[LENGTH];

void AdjustHeap(int a[] , int s){
    int tmp=a[s];
    int leftChild=2*s+1;
    while(leftChild<LENGTH){
        //找到子节点中较大的那个结点
        if(leftChild+1<LENGTH && a[leftChild]<a[leftChild+1]){
            leftChild++;
        }
        //若子结点大于当前结点，交换值，并向下进行循环调整
        if(a[s]<a[leftChild]){
            a[s]=a[leftChild];
            s=leftChild;
            leftChild=2*s+1;
        }
        else{
            break;
        }
        a[s]=tmp;
    }
    printSortArray(a,LENGTH);
}

void HeapSort(int a[]){
    //初始化堆，从最后一个有孩子的结点开始，往前调整
    int i;
    for(i=(LENGTH-1)/2;i>=0;i--){
        AdjustHeap(a,i);
    }
    //排序时从堆的最后一个元素开始向前调整
    for(i=(LENGTH-1);i>=0;i--){
        //交换堆顶元素和末尾的函数，再进行调整
        a[i]=a[0]+a[i];
        a[0]=a[i]-a[0];
        a[i]=a[i]-a[0];
        AdjustHeap(a,i);
    }
}

int main(int argc, char *argv[])
{
    clock_t start,end;
    printSortArray(a,LENGTH);
    start=clock();
    HeapSort(a);
    end=clock();
    double duration=(double)(end-start)/CLOCKS_PER_SEC;
    printSortArray(a[LENGTH],LENGTH);
    printf("排序使用时间%f秒\n", duration );
    return 0;
}
