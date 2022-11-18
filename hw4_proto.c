#include<stdio.h>

int main(void){
    long long int in, a, b, c, d;
    int i;
    scanf("%lld", &in);
    for(i=0 ; i<in ; ++i){
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        int ans = (a+b)==(c+d) ? c-a : ((c+d)-(a+b))+b+c+(((a+b+c+d)*((c+d)-(a+b)-1))/2);
        printf("%d: %lld\n", i+1, ans);
    }
    return 0;
}


