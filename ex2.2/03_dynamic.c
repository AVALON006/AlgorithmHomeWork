#include <stdio.h>
#include <stdlib.h>

int dynamicAddTimes;

int DP_f(int n){
    int res;
    int *dp = (int *)malloc(sizeof(int) * (n+1));
    for (int i = 1; i <= n;i++){
        if(i==1||i==2)
            dp[i] = 1;
        else{
            dynamicAddTimes++;
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    res = dp[n];
    free(dp);
    return res;
}