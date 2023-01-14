#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num, hand;
    char name[25];
    struct node* next;
}Node;

int empty(Node *head){
    if(head) return 0;
    else return 1;
}

Node* search(Node *head, int target){
    Node* current = head;
    while(current!=NULL && current->num!=target)
        current = current->next;
    if(current)
        return current;
    else
        return NULL;
}

void add(Node **headptr){
    Node *current = *headptr;
    if(empty(*headptr)){
        current = (Node*)malloc(sizeof(Node));
        *headptr=current;
    }
    else{
        while(current->next!=NULL)
            current = current->next;
        current->next = (Node*)malloc(sizeof(Node));
        current = current->next;
    }
    printf("Enter part number: ");
    scanf("%d%*c", &current->num);
    printf("Enter part name: ");
    scanf("%[^\n]%*c", current->name);
    printf("Enter quantity on hand: ");
    scanf("%d%*c", &current->hand);
    current->next=NULL;
    printf("\n");
}
int main(void){
    char cmd;
    Node *head = NULL;

    for(;;){
        printf("Enter operation code: ");
        scanf("%c%*c", &cmd);
        int target;
        Node *result;
        switch(cmd){
            case 'i':
                add(&head);
                break;
            case 's':
                printf("Enter part number: ");
                scanf("%d%*c", &target);
                result = search(head, target);
                if(result)
                    printf("Part name: %s\nQuantity on hand: %d\n\n", result->name, result->hand);
                else
                    printf("Part not found.\n\n");
                break;
            case 'u':
                printf("Enter part number: ");
                scanf("%d%*c", &target);
                result = search(head, target);
                if(result){
                    int change;
                    printf("Enter change in quantity on hand: ");
                    scanf("%d%*c", &change);
                    result->hand += change;
                    printf("\n");
                }
                break;
            case 'q':
                return 0;
                break;
            case 'p':
                Node *cur=head;
                printf("Part Number    Part Name               Quantity on Hand\n");
                while(cur!=NULL){
                    printf("%7d        %-24s%9d\n", cur->num, cur->name, cur->hand);
                    cur = cur->next;
                }
                printf("\n");
                break;
        }
    }
}