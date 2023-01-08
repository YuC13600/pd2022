#include<stdio.h>
#include<stdlib.h>

struct node{
    int num, quantity;
    char name[100];
    struct node *next;
};

typedef struct node Node;

int main(void){
    char cmd;
    Node* head=malloc(sizeof(Node));
    head->next=NULL;
    Node* now=head;
    for(;;){
        Node* temp=head;
        int tar;
        printf("Enter operation code: ");
        scanf("%c%*c", &cmd);
        switch(cmd){
            case 'i':
                now->next=malloc(sizeof(Node));
                now=now->next;
                printf("Enter part number: ");
                scanf("%d%*c", &(now->num));
                printf("Enter part name: ");
                scanf("%[^\n]%*c", now->name);
                printf("Enter quantity on hand: ");
                scanf("%d%*c", &(now->quantity));
                now->next = NULL;
                printf("\n");
                break;
            case 's':
                printf("Enter part number: ");
                scanf("%d%*c", &tar);
                while(1){
                    if(temp->num==tar){
                        printf("Part name: %s \n Quantity on hand: %d \n\n", temp->name, temp->quantity);
                        break;
                    }
                    else{
                        if(temp->next==NULL){
                            printf("Part not found.\n");
                            break;
                        }
                        else{
                            temp=temp->next;
                        }
                    }
                }
                break;
            case 'u':
                printf("Enter part number: ");
                scanf("%d%*c", &tar);
                while(1){
                    if(temp->num==tar){
                        printf("Enter change in quantity on hand: ");
                        scanf("%d%*c", &(temp->quantity));
                        break;
                    }
                    else{
                        if(temp->next==NULL){
                            printf("Part not found.\n");
                            break;
                        }
                        else{
                            temp=temp->next;
                        }
                    }
                }
                break;
            case 'p':
                printf("Part Number    Part Name               Quantity on Hand\n");
                while(temp->next!=NULL){
                    printf("%6d          %23s %11d\n", temp->num, temp->name, temp->quantity);
                    temp=temp->next;
                }
                printf("%6d          %23s %11d\n", temp->num, temp->name, temp->quantity);
                break;
            case 'q':
                return 0;
            default: break;
        }
    }
}