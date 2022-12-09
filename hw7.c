#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool* arr;

//return the prime and move to the next smaller prime
int get_arr_value(int* a){
    int re=(*a)--;
    while(!arr[*a]) (*a)--;
    return re;
}

int main(void){
    int in, total=0, tempsum=0, max=0;
    int p=0;
    arr=(bool*)malloc(15001*sizeof(bool));
    for(;;){
        scanf("%d", &in);
        if(in==0) return 0;        
        total=tempsum=0;

        //make prime number list
        if(in>max){
            max=in;
            int i, j;
            for(i=0;i<=max;++i)
                arr[i]=true;
            arr[0]=arr[1]=false;
            for(i=2;i*i<=max;++i) 
                if(arr[i]) 
                    for(j=i*i;j<=max;j+=i)
                        arr[j]=false;
        }

        int p1, p2, i;
        for(i=in;i>0;--i){
            if(arr[i]){
                p1=p2=i;
                break;
            }
        }
        while(p1>0 || tempsum>=in){
            if(tempsum>in){
                tempsum-=get_arr_value(&p2);
                if(tempsum>in) p1=p2;
            }
            else if(tempsum==in){
                total++;
                tempsum+=get_arr_value(&p1);
            }
            else
                tempsum+=get_arr_value(&p1);
        }
        printf("%d\n", total);
    }
}