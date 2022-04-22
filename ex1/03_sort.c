#include <stdio.h>
#include <stdlib.h>

int bubbleSortTimes;

void BubbleSort(int* arr,int len){
    bubbleSortTimes=0;
    int swap=1;
    int i,temp,newBound;
    int bound=len;
//    printf("Func arr=%p\n",arr);
    while(swap&&bound>1){
        swap=0;
//        printf("bound=%d\n",bound);
        for(i=0;i<bound-1;i++){
            bubbleSortTimes++;
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

int mergeSortTimes;
int* mergeSortSize;

void MergeList(int* arr,int s1,int e1,int s2,int e2){
    //由合并排序的划分方法可知，合并的两个列表必然连着
    int* temp=malloc(sizeof(int)*e2-s1);
    int i=s1,j=s2,k=0;
    while(i<e1&&j<e2){
        mergeSortTimes++;
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<e1){
        temp[k++]=arr[i++];
    }
    while(j<e2){
        temp[k++]=arr[j++];
    }
    i=0;j=s1;
    while(j<e2){
        arr[j++]=temp[i++];
    }
    free(temp);
}

void PartMergeSort(int* arr,int s,int e){
    //[s,e)
    mergeSortSize[mergeSortSize[0]++]=e-s;
//    mergeSortSize[mergeSortSize[0]++]=e;
    //printf("s=%d e=%d\n",s,e);
    int i;
    if(e-s<=1){
        return;
    }
    int m=(s+e)/2;
    PartMergeSort(arr,s,m);
    PartMergeSort(arr,m,e);
    //printf("s=%d m=%d e=%d\n",s,m,e);
    MergeList(arr,s,m,m,e);
}

void MergeSort(int* arr,int len){
    mergeSortTimes=0;
    mergeSortSize=(int*)malloc(sizeof(int)*(len*2+1));
    mergeSortSize[0]=1;
    PartMergeSort(arr,0,len);
}

int quickSortTimes;
int* quickSortSize;

int partition(int* arr,int s,int e){
    int i=s,j=e-1;
    int temp=arr[s];
    while(1){
        while(i<e&&arr[i]<=temp){
            quickSortTimes++;
            i++;
        }
        while(j>s&&arr[j]>=temp){
            quickSortTimes++;
            j--;
        }
        if(i<j){
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }else{
            break;
        }
    }
    arr[s]=arr[j];
    arr[j]=temp;
    return j;
}

void PartQuickSort(int* arr,int s,int e){
    //[s,e)
    quickSortSize[quickSortSize[0]++]=e-s;
    if(e-s<=1){
        return;
    }
    int p=partition(arr,s,e);
    //arr[p]处的元素已经确定最终位置
    PartQuickSort(arr,s,p);
    PartQuickSort(arr,p+1,e);
}

void QuickSort(int* arr,int len){
    quickSortTimes=0;
    quickSortSize=(int*)malloc(sizeof(int)*(len*2+1));
    quickSortSize[0]=1;
    PartQuickSort(arr,0,len);
}