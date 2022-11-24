#include<stdio.h>
#include<stdlib.h>

int g(int x, int y){
    int ans=1;
    if(x>y) x^=y^=x^=y;
    int i;
    for(i=1;i<=x;++i)
        if(x%i==0 && y%i==0)
            ans=i;
    return ans;
}
int main(void){
    long long sum1=0, sum2=0, N;
    for(;;){
        scanf("%lld", &N);
        if(N==0) return 0;
        int x;
        for(x=1;x<N;++x)
            sum1+=x;
        x--;
        int y;
        for(y=x+1;y<=N;++y)
            sum2+=y;
        y--;
        printf("%lld\n", sum1*sum2*g(x, y));
    }
}