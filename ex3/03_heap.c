#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define ELEMTYPE Item
//需要时进行修改

int ALTB(ELEMTYPE a,ELEMTYPE b){
    return (float)a.v / a.w < (float)b.v / b.w;
}

typedef struct Heap
{
    //最大堆
    ELEMTYPE *data;
    int len;
} Heap, *pHeap;

pHeap CreateHeap(int n)
{
    pHeap h = (pHeap)malloc(sizeof(Heap));
    h->len = n;
    h->data = (ELEMTYPE *)malloc(sizeof(ELEMTYPE) * h->len);
    return h;
}

void SiftUp(pHeap h, int index)
{
    ELEMTYPE *HT = h->data;//HeapTree
    int len = h->len;
    int i = index;
    if(i<0||i>=len){
        return;
    }
    while (ALTB(HT[(i-1)/2] , HT[i]))
    {
        ELEMTYPE temp = HT[i];
        HT[i] = HT[(i-1)/2];
        HT[(i-1)/2] = temp;

        i = (i-1)/2;
    }
}

void SiftDown(pHeap h,int index){
    ELEMTYPE *HT = h->data;
    int len = h->len;
    int i = index;
    while((2*i+1)<len){
        i = (2*i+1);
        if(i+1<len&&ALTB(HT[i],HT[i+1])){
            //比较左右子树大的那个
            i = i + 1;
        }
        if(ALTB(HT[(i-1)/2],HT[i])){
            ELEMTYPE temp = HT[i];
            HT[i] = HT[(i-1)/2];
            HT[(i-1)/2] = temp;
        }
    }
}

ELEMTYPE DeleteElem(pHeap h,int index){
    ELEMTYPE x = h->data[index];
    if(index==h->len-1){
        return x;
    }
    h->data[index] = h->data[h->len-1];
    h->len--;
    SiftDown(h, index);
    return x;
}

ELEMTYPE DeleteMax(pHeap h){
    return DeleteElem(h,0);
}

pHeap MakeHeap(ELEMTYPE* arr,int arrLen){
    pHeap h = (pHeap)malloc(sizeof(Heap));
    h->data = arr;//在位调整
    h->len = arrLen;
    for (int i = (arrLen-1) / 2; i >= 0;i--){
        SiftDown(h, i);
    }
    return h;
}

void FreeHeap(pHeap h)
{
    free(h->data);
    free(h);
}