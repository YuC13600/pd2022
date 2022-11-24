#include<stdio.h>

int g(int x, int y){
    if(x) while((x%=y) && (y%=x));
    return x+y;
}
int main(void){
    int N;
    for(;;){
        int sum=0;
        scanf("%lld", &N);
        if(N==0) return 0;
        int x;
        for(x=1;x<N;++x){
            int y;
            for(y=x+1;y<=N;++y)
                sum+=g(x, y);
        }
        printf("%d\n", sum);
    }
}