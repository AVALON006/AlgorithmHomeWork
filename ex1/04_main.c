#include <stdio.h>
#include <stdlib.h>
#include "02_lcg.c"
#include "03_sort.c"

const int showCeil=30;
const char line[]="-----------------------------------------------------\n";

void printArr(int* arr,int n){
    int i,temp=showCeil;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
        if(i>temp){
            printf("\n");
            temp+=showCeil;
        }
    }
    printf("\n");
}

int* RandomArr(int n,int floor,int ceil){
    int* arr=malloc(sizeof(int)*n);
    int i;
    InitRandom();
    for(i=0;i<n;i++){
        int num=Random();
        if(num<0){
            num=num*(-1);
        }
//        printf("%d\n",num%(ceil-floor));
        arr[i]=(num%(ceil-floor))+floor;
    }
    return arr;
}

void testSort(void(*Sort)(int* arr,int len),int n,int floor,int ceil){
    int* arr=RandomArr(n,floor,ceil);
    printf("排序前：\n");
    printArr(arr,n);
    Sort(arr,n);
    printf("排序后：\n");
    printArr(arr,n);
    free(arr);
}

int main() 
{
    int n,floor,ceil;
    printf("请输入数组长度：");
    scanf("%d",&n);
    fflush(stdin);
    printf("请输入随机数范围（0 100）：");
    int success=scanf("%d %d",&floor,&ceil);
    if(success!=2){
        floor=0;
        ceil=100;
    }

    printf(line);
    printf("冒泡排序\n");
    testSort(BubbleSort,n,floor,ceil);
    printf("冒泡总共比较次数=%d\n",bubbleSortTimes);

    printf(line);
    printf("合并排序\n");
    testSort(MergeSort,n,floor,ceil);
    printf("合并排序总共比较次数=%d\n",mergeSortTimes);
    printf("合并排序问题规模：\n");
    printArr(&mergeSortSize[1],mergeSortSize[0]);

    printf(line);
    printf("快速排序\n");
    testSort(QuickSort,n,floor,ceil);
    printf("快速排序总共比较次数=%d\n",quickSortTimes);
    printf("快速排序问题规模：\n");
    printArr(&quickSortSize[1],quickSortSize[0]);

    free(mergeSortSize);
    free(quickSortSize);
    return 0;
}