#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int num, hand;
    char name[25];
    struct node* next;
};
typedef struct node Node;

int main(void){
    char cmd;
    Node* head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    for(;;){
        printf("Enter operation code: ");
        scanf("%c%*c", &cmd);
        Node* current = head;
        int tar;
        switch (cmd){
            case 'i':
                while(current->next!=NULL){
                    current=current->next;
                }
                current->next=(Node*)malloc(sizeof(Node));
                current=current->next;
                printf("Enter part number: ");
                scanf("%d%*c", &(current->num));
                printf("Enter part name: ");
                scanf("%[^\n]%*c", &(current->name));
                printf("Enter quantity on hand: ");
                scanf("%d%*c", &(current->hand));
                current->next=NULL;
                break;
            case 's':
                printf("Enter part number: ");
                scanf("%d%*c", &tar);
                while(current!=NULL){
                    if(current->num == tar){
                        printf("Part name: %s\n", current->name);
                        printf("Quantity on hand: %d\n", current->hand);
                        break;
                    }
                    else current=current->next;
                }
                if(current==NULL){
                    printf("Part not found.\n");
                }
                break;
            case 'u':
                printf("Enter part number: ");
                scanf("%d%*c", &tar);
                while(current!=NULL){
                    if(current->num == tar){
                        int mod;
                        printf("Enter change in quantity on hand: ");
                        scanf("%d%*c", &mod);
                        current->hand+=mod;
                        break;
                    }
                    else current=current->next;
                }
                if(current==NULL){
                    printf("Part not found.\n");
                }
                break;
            case 'p':
                printf("Part Number    Part Name               Quantity on Hand\n");
                current=current->next;
                while(current->next!=NULL){
                    printf("%7d        %-24s%9d\n", current->num, current->name, current->hand);
                    current=current->next;
                }
                printf("%7d        %-24s%9d\n", current->num, current->name, current->hand);
                break;
            case 'q':
                return 0;
                break;
            default:
                break;
        }
        printf("\n");
    }
}