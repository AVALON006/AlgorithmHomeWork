#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int KnapsackDP(int v[],int w[],int C,int n){
    int** m=(int**)malloc(sizeof(int*)*(n+1));
    for (int i = 0; i <= n;i++){
        m[i] = (int *)malloc(sizeof(int) * (C+1));
        m[i][0] = 0;
    }
    for (int j = 0; j <= C;j++){
        m[0][j] = 0;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= C;j++){
            m[i][j] = m[i - 1][j];
            if(w[i-1]<=j){
                m[i][j] = fmax(m[i][j], m[i - 1][j - w[i-1]] + v[i-1]);
            }
        }
    }
    int res = m[n][C];
    for (int i = 0; i < n;i++){
        free(m[i]);
    }
    free(m);
    return res;
}