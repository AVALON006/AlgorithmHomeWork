#include <stdio.h>
#include <stdlib.h>
#include "02_lcg.c"
#include "03_sort.c"

//const int showCeil=30;
const char line[]="-----------------------------------------------------\n";

void fprintArr(FILE* fp,int* arr,int n){
    int i;
    for(i=0;i<n;i++){
        fprintf(fp,"%d ",arr[i]);
    }
    fprintf(fp,"\n");
}

void printArr(int* arr,int n){
    //int i,temp=showCeil;
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
        // if(i>temp){
        //     printf("\n");
        //     temp+=showCeil;
        // }
    }
    printf("\n");
}

int* RandomArr(int n,int floor,int ceil){
    int* arr=malloc(sizeof(int)*n);
    int i;
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

void ftestSort(FILE* fp,void (*Sort)(int* arr,int n),int n,int floor,int ceil){
    int* arr=RandomArr(n,floor,ceil);
    //printf("排序前：\n");
    //printf("排序前：");
    fprintf(fp,"排序前：\n");
    //printArr(arr,n);
    fprintArr(fp,arr,n);
    Sort(arr,n);
    //printf("排序后：\n");
    //printf("排序后：");
    fprintf(fp,"排序后：\n");
    //printArr(arr,n);
    fprintArr(fp,arr,n);
    free(arr);   
}

void testSort(void(*Sort)(int* arr,int len),int n,int floor,int ceil){
    int* arr=RandomArr(n,floor,ceil);
    //printf("排序前：\n");
    printf("排序前：");
    printArr(arr,n);
    Sort(arr,n);
    //printf("排序后：\n");
    printf("排序后：");
    printArr(arr,n);
    free(arr);
}

void test(char* filename,int n){
    seed=time(NULL)*a;
    int floor,ceil;
    // printf("请输入数组长度：");
    // scanf("%d",&n);
    // fflush(stdin);
    // printf("请输入随机数范围（0 100）：");
    // int success=scanf("%d %d",&floor,&ceil);
    // if(success!=2){
    //     floor=0;
    //     ceil=100;
    // }
    floor=-1000;ceil=1000;
    FILE* fp=fopen(filename,"w");
    fprintf(fp,"n=%d floor=%d ceil=%d\n",n,floor,ceil);

    //printf(line);
    fprintf(fp,line);
    //printf("冒泡排序\n");
    fprintf(fp,"冒泡排序\n");
    //testSort(BubbleSort,n,floor,ceil);
    ftestSort(fp,BubbleSort,n,floor,ceil);
    //printf("冒泡总共比较次数=%d\n",bubbleSortTimes);
    fprintf(fp,"冒泡总共比较次数=%d\n",bubbleSortTimes);

    //printf(line);
    fprintf(fp,line);
    //printf("合并排序\n");
    fprintf(fp,"合并排序\n");
    //testSort(MergeSort,n,floor,ceil);
    ftestSort(fp,MergeSort,n,floor,ceil);
    //printf("合并排序总共比较次数=%d\n",mergeSortTimes);
    fprintf(fp,"合并排序总共比较次数=%d\n",mergeSortTimes);
    //printf("合并排序问题规模：\n");
    //printf("合并排序问题规模：");
    fprintf(fp,"合并排序问题规模：");
    //printArr(&mergeSortSize[1],mergeSortSize[0]);
    fprintArr(fp,&mergeSortSize[1],mergeSortSize[0]-1);

    //printf(line);
    fprintf(fp,line);
    //printf("快速排序\n");
    fprintf(fp,"快速排序\n");
    //testSort(QuickSort,n,floor,ceil);
    ftestSort(fp,QuickSort,n,floor,ceil);
    //printf("快速排序总共比较次数=%d\n",quickSortTimes);
    fprintf(fp,"快速排序总共比较次数=%d\n",quickSortTimes);
    //printf("快速排序问题规模：\n");
    //printf("快速排序问题规模：");
    fprintf(fp,"快速排序问题规模：");
    //printArr(&quickSortSize[1],quickSortSize[0]);
    fprintArr(fp,&quickSortSize[1],quickSortSize[0]-1);

    free(mergeSortSize);
    free(quickSortSize);
}

int main() 
{
    InitRandom();
    test("data1.txt",100);
    test("data2.txt",100);

    test("data3.txt",1000);
    test("data4.txt",3000);
    test("data5.txt",5000);
    test("data6.txt",7000);
    test("data7.txt",9000);
    test("data8.txt",10000);
    test("data9.txt",12000);
    test("data10.txt",14000);
    test("data11.txt",16000);
    test("data12.txt",18000);
    test("data13.txt",20000);
    return 0;
}