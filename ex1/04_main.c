#include <stdio.h>
#include <stdlib.h>
#include "02_lcg.c"
#include "03_sort.c"

const int showCeil=15;

void printArr(int* arr,int n){
    int i,temp=showCeil;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
        if(i>temp){
            temp=temp+i;
            printf("\n");
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
    
    printf("floor=%d,ceil=%d\n",floor,ceil);
    
    int* arr=RandomArr(n,floor,ceil);
    int times;
    printf("\n排序前\n");
    printArr(arr,n);
    BubbleSort(arr,n,&times);
    printf("\n总共比较次数=%d\n",times);
    printf("\n排序后\n");
    printArr(arr,n);
    free(arr);
    return 0;
}