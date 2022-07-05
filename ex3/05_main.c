#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "02_lcg.c"
#include "04_greedy.c"

#define VALUE_MAX 100
#define TEST_ITEM_NUM 10
#define DATA_FILE_NAME "result.txt"
const char line[] = "-----------------------------------------------------\n";

void HeapSort(ELEMTYPE *arr, int arrLen);
void fprintArr(FILE *fp, int *arr, int n);
void testOneNum(FILE *fp, int m, int n);

int main()
{
    const int m = 500;
    InitRandom();
    int n[TEST_ITEM_NUM] = {10, 20, 40, 100, 200, 400, 800, 2000,5000,10000};
    //需要测试的背包物品的数量
    FILE *fp = fopen(DATA_FILE_NAME, "w");
    fprintf(fp, "背包容量：%d\n", m);
    fprintf(fp, line);
    for (int i = 0; i < TEST_ITEM_NUM; i++)
    {
        testOneNum(fp, m,n[i]);
    }
    fclose(fp);
    return 0;
}

void HeapSort(ELEMTYPE *arr, int arrLen)
{
    pHeap h = MakeHeap(arr, arrLen);
    for (int i = arrLen - 1; i > 0; i--)
    {
        ELEMTYPE temp = h->data[i];
        h->data[i] = h->data[0];
        h->data[0] = temp;
        h->len--;
        SiftDown(h, 0);
    }
    for (int i = 0; i <= arrLen/2;i++){
        ELEMTYPE temp = arr[i];
        arr[i] = arr[arrLen - i - 1];
        arr[arrLen - i - 1] = temp;
    }
}

void fprintArr(FILE *fp, int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }
    fprintf(fp, "\n");
}

void testOneNum(FILE* fp,int m,int n){
    LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;

    //之所以要把m传进来是因为const int m表示整数int型最大值
    float *x = (float *)malloc(sizeof(float) * n);
    int *w = (int *)malloc(sizeof(int) * n);
    int *v=(int *)malloc(sizeof(int) * n);
    pItem items = (pItem)malloc(sizeof(Item) * n);
    for (int i = 0; i < n; i++)
    {
        items[i].w = (abs(Random()) % m / 2)+1;
        //物品重量应为正值
        items[i].v = abs(Random()) % VALUE_MAX;
        //设置物品的最大价值
    }
    QueryPerformanceCounter(&time_start);	//计时开始
    HeapSort(items, n);
    for (int i = 0; i < n;i++){
        v[i] = items[i].v;
        w[i] = items[i].w;
    }
    KnapsackGreedy(v, w, m, n, x);
    QueryPerformanceCounter(&time_over);	//计时结束
	double run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
    fprintf(fp, "物品数量：%d\n", n);
    fprintf(fp, "求解花费时间：%f\n", run_time/1000);
    fprintf(fp, "解向量：");
    for (int j = 0; j < n; j++)
    {
        fprintf(fp, "%f ", x[j]);
    }
    fprintf(fp, "\n");
    fprintf(fp, "物品重量：");
    fprintArr(fp, w, n);
    fprintf(fp, "物品价值：");
    fprintArr(fp, v, n);
    fprintf(fp, "物品性价比：");
    for (int j = 0; j < n; j++)
    {
        fprintf(fp, "%f ", (float)v[j]/w[j]);
    }
    fprintf(fp, "\n");
    fprintf(fp, line);
    free(items);
    free(x);
    free(w);
    free(v);
}
