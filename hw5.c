#include<stdio.h>
#include<stdlib.h>

static int intcompare(const void *p1, const void *p2){
    int a = *((int*)p1);
    int b = *((int*)p2);
    
    if(a==b)return 0;
    else if(a<b)return -1;
    else return 1;
}

int absl(int in){
    return in<0 ? -in : in;
}

int main(void){
    int in, i;
    while(scanf("%d", &in)!=EOF){
        int *arr = (int*)malloc(sizeof(int)*(in-1));
        int a;
        scanf("%d", &a);
        for(i=0;i<in-1;++i){
            int b;
            scanf("%d", &b);
            arr[i] = absl(a-b);
            a = b;
        }
        qsort(arr, in-1, sizeof(int), intcompare);
        for(i=1;i<in;++i){
            if(arr[i-1]!=i){
                printf("No\n");
                break;
            }
            else if(i==in-1)
                printf("Yes\n");
        }
    }
    return 0;
}