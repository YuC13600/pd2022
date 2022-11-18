#include<stdio.h>

int main(void){
    int a1, a2, b1, b2;
    for(;;){
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        if(a1==0 && a2==0 && b1==0 && b2==0)
            return 0;
        else{
            if(a1==b1 && b2<a2){
                printf("%d\n", 1380+(60+b2-a2));
                continue;
            }
            if(b1<a1)
                b1+=24-a1;
            else
                b1-=a1;
            if(b2<a2){
                b2+=60-a2;
                b1--;
            }
            else 
                b2-=a2;
            printf("%d\n", b1*60+b2);                
        }
    }
}