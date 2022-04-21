#include <stdio.h>

void BubbleSort(int* arr,int len,int* times){
    *times=0;
    int swap=1;
    int i,temp,newBound;
    int bound=len;
//    printf("Func arr=%p\n",arr);
    while(swap&&bound>1){
        swap=0;
//        printf("bound=%d\n",bound);
        for(i=0;i<bound-1;i++){
            (*times)=(*times)+1;
            if(arr[i]>arr[i+1]){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                swap=1;
                newBound=i+1;
            }
        }
        bound=newBound;
    }
}