#include <stdio.h>
#include <stdlib.h>

int divideAddTimes;

int f(int n){
    if (n == 1 || n == 2) return 1;
    else{
        divideAddTimes++;
        return f(n - 1) + f(n - 2);
    }
}

int DAC_f(int n){
    divideAddTimes = 0;
    return f(n);
}