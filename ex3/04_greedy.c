#include <stdio.h>
#include <stdlib.h>
#include "03_heap.c"

void KnapsackGreedy(int v[],int w[],int m,int n,float* x){
    //v是物品价值，w是物品重量，同时二者是经过vi/wi≥v(i+1)/w(i+1)排序的
    //m是背包容量，n是物品数量，x是解向量
    for (int i = 0; i < n;i++){
        x[i] = 0;
    }
    int cu = m;//背包剩余容量
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if(w[i]>cu) break;
        x[i] = 1;
        cu = cu - w[i];
    }
    if(i<=n){
        x[i] = (float)cu / w[i];
    }
}
