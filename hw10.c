#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int charcompare(const void *p1, const void *p2){
    char a=*((char*)p1);
    char b=*((char*)p2);
    
    if(a==b) return 0;
    else if(a<b) return -1;
    else return 1;
}
int st=1;
int main(void){
    char inputstr[1510];
    char* input;
    while(scanf("%[^\n]%*c",inputstr)!=EOF){
        if(st)
            st=0;
        else
            printf("\n");
        int i, j;
        int len = strlen(inputstr);
        qsort(inputstr, len, sizeof(char), charcompare);
        int s=0;
        while(((int)inputstr[s])<=31)
            s++;
        input=(inputstr+s);
        len=strlen(input);
        char carr[1500]={0};
        int iarr[1500]={0};
        int arrCounter=0;
        if(len>0){
            carr[0]=input[0];
            iarr[0]=1;
        }
        for(i=1;i<len;++i){
            if(input[i]==carr[arrCounter])
                iarr[arrCounter]++;
            else{
                arrCounter++;
                carr[arrCounter]=input[i];
                iarr[arrCounter]=1;
            }
        }
        arrCounter++;
        for(i=arrCounter-1;i>0;--i){
            for(j=0;j<i;++j){
                if(iarr[j]>iarr[j+1] || (iarr[j]==iarr[j+1] && carr[j]<carr[j+1])){
                    iarr[j]^=iarr[j+1]^=iarr[j]^=iarr[j+1];
                    carr[j]^=carr[j+1]^=carr[j]^=carr[j+1];
                }
            }
        }
        for(i=0;i<arrCounter;++i){
            printf("%d %d\n", (int)carr[i], iarr[i]);
        }
    }
    return 0;
}