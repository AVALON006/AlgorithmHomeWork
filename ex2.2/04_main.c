#include <stdio.h>
#include <stdlib.h>
#include "02_divide.c"
#include "03_dynamic.c"

const char line[]="-----------------------------------------------------\n";

#define testNum 7
int main()
{
    int n[testNum] = {5,10,15,20,25,30,35};
    // int divt[testNum];
    // int dynt[testNum];
    FILE *fp = fopen("result.txt", "w");
    for (int i = 0; i < testNum;i++){
        fprintf(fp,"f(%d)=%d\n",n[i],DAC_f(n[i]));
        // printf("f(%d)=%d\n",n[i],DAC_f(n[i]));
        DAC_f(n[i]);
        DP_f(n[i]);
        // divt[i] = divideAddTimes;
        // dynt[i] = dynamicAddTimes;
        // printf("分治法加了%d次\n", divideAddTimes);
        // printf("动态规划法加了%d次\n", dynamicAddTimes);
        fprintf(fp,"分治法加了%d次\n", divideAddTimes);
        fprintf(fp,"动态规划法加了%d次\n", dynamicAddTimes);
        fprintf(fp, line);
    }
    fclose(fp);
    return 0;
}