#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "02_lcg.c"
#include "03_knapsack.c"

#define VALUE_MAX 5000
#define MORE_WEIGHT 1.2
#define TEST_CAP_NUM 5
#define TEST_ITEM_NUM 9
#define DATA_FILE_NAME "data"
#define ZERO_ACSII 0x30

const char line[]="-----------------------------------------------------\n";

void test(int C, int n, char *filename);
void printArr(int *arr, int n);
void fprintArr(FILE *fp, int *arr, int n);

int correctTest(){
    int c = 9;
    int n = 4;
    int w[4] = {2,3,4,5};
    int v[4] = {3,4,5,7};
    printf("结果为：%d\n",KnapsackDP(v, w, c, n));
    return 0;
}

int main(){
    char filename[255];
    char fileSerialNum[255];
    InitRandom();
    int C[TEST_CAP_NUM] = {200,400,800,2000,100000};
    //需要测试的背包的容量
    int n[TEST_ITEM_NUM] = {10, 20, 40, 100, 200, 400, 800, 2000,5000};
    //需要测试的背包物品的数量
    for (int i = 0; i < TEST_CAP_NUM;i++){
        strcpy(filename, DATA_FILE_NAME);
        itoa(i+1, fileSerialNum, 10);
        strcat(filename, fileSerialNum);
        strcat(filename, ".txt");
        FILE* fp = fopen(filename, "w");
        fprintf(fp, "背包容量为：%d\n", C[i]);
        fprintf(fp, line);
        fclose(fp);
        for (int j = 0; j < TEST_ITEM_NUM; j++)
        {
            test(C[i], n[j], filename);
        }
    }
    return 0;
}

void test(int C,int n,char* filename){
    clock_t s, e;
    int *w = (int *)malloc(sizeof(int) * n);
    int *v=(int *)malloc(sizeof(int) * n);
    for(int i=0;i<n;i++){
        w[i]=abs(Random() % C*MORE_WEIGHT);
        //设置一些会超过背包容量的物品重量
        //物品重量不应为负值
        v[i]=Random() % VALUE_MAX;
        //设置物品的最大价值
    }
    s = clock();
    int max=KnapsackDP(v,w,C,n);
    e = clock();
    // printf("最大值为：%d\n", max);
    FILE* fp=fopen(filename,"a");
    if (fp==NULL)
    {
        FILE* fp=fopen(filename,"w");   
    }
    // fprintf(fp, "背包容量为：%d\n", C);
    fprintf(fp, "物品数量为：%d\n", n);
    fprintf(fp,"背包能装的最大价值为：%d\n",max);
    fprintf(fp, "计算花费时间（毫秒）为：%f\n", ((double)e - s) / (CLOCKS_PER_SEC/1000));
    fprintf(fp, "物品重量为：");
    fprintArr(fp, w, n);
    fprintf(fp, "物品价值为：");
    fprintArr(fp, v, n);
    fprintf(fp, line);
    fclose(fp);
    free(w);
    free(v);
}

void printArr(int* arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void fprintArr(FILE* fp,int* arr,int n){
    int i;
    for(i=0;i<n;i++){
        fprintf(fp,"%d ",arr[i]);
    }
    fprintf(fp,"\n");
}