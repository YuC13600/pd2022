#include<stdio.h>

int main(void){
    int in, i;
    scanf("%d", &in);
    for(i=0;i<in;++i){
        int a, b, c, sum = 0;
        scanf("%d %d %d", &a, &b, &c);
        a += b;
        while(a/c != 0){
            sum += a/c;
            a = a%c + a/c;
        }
        printf("%d\n", sum);
    }
}