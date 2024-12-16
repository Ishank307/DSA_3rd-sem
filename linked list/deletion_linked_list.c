/*
C PROGRAM TO DELETE A SPECIFIC ELEMENT IN A LINKED LIST 
Author = ISHANK KUMAR
USN = 2SD23CS039
*/
//preprocessor directories
#include<stdio.h>
#include<stdlib.h>

//STRUCTURE OF THE NODE
struct node{
    int data;
    struct node * link;
};

// Function to create a new node
struct node *getnode(){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("MEMORY ALLOCATION FAILED");
        return NULL;
    }
    return temp;
}

// Function to insert an element at the front of the linked list
struct node * fnInsertfront(struct node *f,int x){
    
    struct node * temp;
    temp=getnode();
    temp->data=x;
    temp->link=f;
    return temp;;
}

// Function to delete a specific element from the linked list
struct node * fn_delete_specific(struct node *f,int k){
    if (f==NULL){
        printf("Memory empty");
        return NULL;
    }
    struct node *curr,*prev;
    curr=f;
    if(f->data==k){
        f=f->link;
        return f;
    }
    while(curr!=NULL){
        if(curr->data==k){
            prev->link=curr->link;
            printf("deleted element is %d\n",k);
            free(curr);
            return f;
        }
        prev=curr;
        curr=curr->link;

    }
    printf("Node with key %d not found in the list.\n", k);
    return f;
}

// Function to display all elements in the linked list
void display(struct node * f){
    if (f==NULL){
        printf("list empty");
        return;
    }

    struct node * temp;
    temp=f;
    while(temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->link;
}

}

// Main function to provide a menu-driven interface for the linked list operations
int main(){
    struct node *first = NULL;
    int element,ichoice,key;
    for(;;){
    printf("Enter the choice\n1.)Insert first\n2.)delete specific\n3.)display");
    scanf("%d",&ichoice);
        switch(ichoice){
            case 1: printf("Enter the element to be inserted\n");
                    scanf("%d",&element);
                    first=fnInsertfront(first,element);
                    break;
            case 2: printf("Enter the key element to be deleted");
                    scanf("%d",&key);
                    first=fn_delete_specific(first,key);
                    break;
            case 3: display(first);
                    break;
            default: printf("invalid case");
                    break;

        }



     }
    return 0;
}