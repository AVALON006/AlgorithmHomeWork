#include <stdio.h>
#include <time.h>

const int a=214013;
const int m=1<<31-1;//最大int整数
const int c=2531011;

int seed=1;

void InitRandom(){
    seed=time((time_t *)NULL);
}

int Random(){
    seed=(a*seed+c)%m;
    return seed;
}
