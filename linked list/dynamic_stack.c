#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node* NODE;

NODE getnode(){
    NODE temp=(NODE)malloc(sizeof(struct node));

    if(temp==NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    temp->data=0;
    temp->link=NULL;
    return temp;
}

NODE insert_first(NODE first,int value){
    NODE temp;
    temp= getnode();
    if(temp==NULL){
        printf("Memory allocation failed");
        exit(0);
    }
    temp->data=value;
    temp->link=first;
    return temp;
}

NODE delete_front(NODE first){
    if(first==NULL){
        printf("List is empty");
        return first;
    }
    NODE temp=first;
    first=temp->link;
    free(temp);
    return first;
}

void display_list(NODE first){

    NODE temp=first;
    while(temp!= NULL){
        printf("%d\n",temp->data);
        temp=temp->link;
    }

    printf("NULL\n"); //indicates the end of the list
}

int peek_element(NODE first){
    if(first==NULL){
        printf("stack is empty");
        return -1;
    }
    return first->data;
}

void main(){
    NODE first=NULL,rear;
    int element;
    int choice;
    for(;;){
        printf("Enter the choice\n1.)Insert Node\n2.)delete node\n3.)display\n");
        scanf("%d",&choice);    
        switch(choice){
        case 1: printf("Enter the element to be inserted\n");
                scanf("%d",&element);
                first=insert_first(first,element);
                break;
        case 2: printf("Deleted element is %d\n",peek_element(first));
                first=delete_front(first);
                break;
        case 3: display_list(first);
                break;
        default: printf("invalid case");
                break;
    }
    }
}