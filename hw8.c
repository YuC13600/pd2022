#include<stdio.h>

int main(void){
    int in, sum=0;
    for(;;){
        scanf("%d", &in);
        if(!in) return 0;
        while(in>=10){
            sum=0;
            do{
                sum+=in%10;
            }while(in/=10);
            in=sum;
        }
        printf("%d\n", in);
    }
}