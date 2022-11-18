#include<stdio.h>
#include<stdlib.h>

void chk(int* arr){
    int a=arr[0], b=arr[1], c=arr[2];

    //IS
    if(a == b){
        printf("IS\n");
        return;
    }

    //IM
    if(b/8!=c/8 && b%8!=c%8){
        printf("IM\n");
        return;
    }
    if(a==c || b==c){
        printf("IM\n");
        return;
    }
    if(b/8==c/8 && b/8==a/8){
        if((b%8>a%8 && a%8>c%8) || (b%8<a%8 && a%8<c%8)){
            printf("IM\n");
            return;
        }
    }
    if(b%8==c%8 && b%8==a%8){
        if((b/8>a/8 && a/8>c/8) || (b/8<a/8 && a/8<c/8)){
            printf("IM\n");
            return;
        }
    }

    //MNA
    if(a/8==c/8){
        if(a%8==c%8+1 || a%8==c%8-1){
            printf("MNA\n");
            return;
        }
    }
    if(a%8==c%8){
        if(a/8==c/8+1 || a/8==c/8-1){
            printf("MNA\n");
            return;
        }
    }

    //A
    if(a/8+1!=c/8 && a/8+1<8){
        printf("A\n");
        return;
    }
    if(a/8-1!=c/8 && a/8-1>=0){
        printf("A\n");
        return;
    }
    if(a%8+1!=c%8 && a%8+1<8){
        printf("A\n");
        return;
    }
    if(a%8-1!=c%8 && a%8-1>=0){
        printf("A\n");
        return;
    }

    //S
    printf("S\n");
    return;
}

int main(void){
    int arr1[3], i;
    for(;;){
        for(i=0;i<3;++i){
            if(scanf("%d", &arr1[i]) == EOF)
                return 0;
        }
        chk(arr1);
    }
    return 0;
}