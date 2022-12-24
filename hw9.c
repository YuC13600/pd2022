#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int n, int* arr){
    int i, j, step=0;
    for(j=n-1;j>0;--j){
        for(i=0;i<j;++i){
            if(arr[i]>arr[i+1]){
                arr[i]^=arr[i+1]^=arr[i]^=arr[i+1];
                ++step;
            }
        }
    }
    return step;
}

int main(void){
    int step=0, datas=0, thisdata=0, i;
    scanf("%d", &datas);
    while(datas--){
        step=0;
        scanf("%d", &thisdata);
        int* arr=(int*)malloc(sizeof(int)*thisdata);
        for(i=0;i<thisdata;++i)
            scanf("%d", &arr[i]);
        step = bubbleSort(thisdata, arr);
        printf("%d\n", step);
    }
}