#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * getnode(){
    struct node * temp;
    temp= (struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory allocation failed");
        exit(0);
    }
    temp->data=0;
    temp->next=NULL;
    return temp;
}



struct node *fn_insertfront(struct node *f,int element){
    struct node *temp;
    temp=getnode();
    temp->data=element;
    temp->next=f;
    return temp;
} 


struct node * fn_deletefront(struct node *f){
    if (f==NULL){
        printf("Memory empty");
        return NULL;
    }
    struct node * temp;
    temp=f;
    temp=temp->next;
    printf("Deleted element is %d",f->data);
    free(f);
    return temp;
}

struct node * fn_InsertRear(struct node * f,int x){
    struct node * temp;
    struct node * curr;
    temp=getnode();
    temp->data=x;
    temp->next=NULL;
    curr=f;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return f;
}

struct node * delete_Rear(struct node *f){
    struct node *curr,*prev;
    if(f==NULL){
        printf("list is empty");
        return NULL;
        
    }
    if(f->next==NULL){
        printf("deleted element is %d",f->data);
        free(f);
        return NULL;
    }
    curr=f;
    prev=NULL;
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }
    printf("deleted element is %d",curr->data);
    prev->next=NULL;
    free(curr);
    return f;
}

struct node *priority(struct node *f,int x){
    struct node *curr,*temp,*prev;
    temp=getnode();
    temp->data=x;
    temp->next=NULL;
    if (f==NULL)
    {
        return temp;
    }
    if (x<f->data)
    {
        temp->next=f;
        return temp;
    }
    curr=f;
    prev=NULL;
    
    while(curr!=NULL&&curr->data<x){
        prev=curr;
        curr=curr->next;
    }
    prev->next=temp;
    temp->next=curr;
    return f;
}

struct node * fnInsertAfter(struct node *f,int x,int k){
    struct node *temp,*curr;
    if(f==NULL){
        printf("list is empty");
        return NULL;
    }
    curr=f;
    while (curr!=NULL&& curr->data!=k){
        curr=curr->next;
    }
    if(curr!=NULL){
        temp=getnode();
        temp->data=x;
        temp->next=curr->next;
        curr->next=temp;
    }
    else{
        printf("key element is not found");
    }
    return f;

}

struct node * fn_insertBefore(struct node *f,int x,int k){
    struct node * temp,*curr,*prev;
    if(f==NULL){
        printf("List is empty");
        return NULL;
    }
    curr=f;
    temp=getnode();
    temp->data=x;
    temp->next=NULL;
    
    if(f->data==k){
    temp->next=f;
    return temp;
    }

    while(curr!=NULL&&curr->data!=k){
        prev=curr;
        curr=curr->next;
    }

    if(curr!=NULL){
        temp->next=curr;
        prev->next=temp;
    }
    return f;

}

struct node * fn_delete_element(struct node * f,int key){
    struct node *curr,*prev;
    if(f==NULL){
        printf("List empty can't delete");
        return NULL;
    }
    if(f->data==key){
        f=f->next;
        free(curr);
        return f;}
    curr=f;
    prev=NULL;
    while(curr!=NULL&&curr->data!=key){
        prev=curr;
        curr=curr->next;
    }
    if(curr!=NULL){
        prev->next=curr->next;
        printf("Deleted element is %d",key);
        free(curr);
    }
    else 
        printf ("key not found");
   
    return f;

}

void display(struct node * first){
    if (first==NULL){
        printf("list empty");
        return;
    }
    struct node * temp=first;
    while(temp->next!= NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void main(){
    struct node * first;
    first=getnode();
    first->next=NULL;
    int element;
    int choice;
    for(;;){
        printf("Enter the choice\n1.)Insert first\n2.)delete first\n3.)insertrear\n4.)delete rear\n5.)insert priority\n 6.) insert after \n7.) insert before\n8.) display");
        scanf("%d",&choice);    
        switch(choice){
        case 1: printf("Enter the element to be inserted\n");
                scanf("%d",&element);
                first=fn_insertfront(first,element);
                break;
        case 2: first=fn_deletefront(first);
                break;
        case 3: printf("Enter the element to be inserted at rear\n");
                scanf("%d", &element);
                first = fn_InsertRear(first, element);
                break;

        case 4: first = delete_Rear(first);
                break;
        case 5: printf("Enter the element to insert in priority order\n");
                scanf("%d", &element);
                first = priority(first, element);
                break;

        case 6: printf("Enter the element to insert\n");
                scanf("%d", &element);
                int afterElement;
                printf("Enter the element after which to insert\n");
                scanf("%d", &afterElement);
                first = fnInsertAfter(first, element, afterElement);
                break;

        case 7: printf("Enter the element to insert\n");
                scanf("%d", &element);
                int beforeElement;
                printf("Enter the element before which to insert\n");
                scanf("%d", &beforeElement);
                first = fn_insertBefore(first, element, beforeElement);
                break;
        case 8: printf("Enter the element to delete\n");
            scanf("%d", &element);
            first = fn_delete_element(first, element);
            break;

        case 9: display(first);
                break;
        default: printf("invalid case");
                break;
    
    }

    }
}

