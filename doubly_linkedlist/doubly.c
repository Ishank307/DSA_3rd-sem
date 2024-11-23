#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node * NODE;

NODE getnode(){
    NODE temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    return temp;
}

NODE fnInsertfront(NODE head,int item){
    NODE curr;
    NODE temp;
    temp=getnode();
    temp->info=item;
    curr=head->rlink;
    temp->rlink=curr;
    curr->llink=temp;
    head->rlink=temp;
    temp->llink=head;

    return head;
}

NODE fndeletefront(NODE head){
    NODE curr,next;
    curr=head->rlink;
    next=curr->rlink;
    head->rlink=next;
    next->llink=head;
    free(curr);
    return head;
}

NODE fnInsertrear(NODE head,int item){
    



}
void display(NODE head){
    NODE curr;
    curr=head->rlink;
    while(curr!=head){
        printf("%d\n",curr->info);
        curr=curr->rlink;
    }


}

void main(void){
    NODE head;
    head=getnode();
    head->info=0;
    head->llink=head->rlink=head;
    head=fnInsertfront(head,8);
    head=fnInsertfront(head,10);
    head=fnInsertfront(head,18);
    head=fndeletefront(head);
    display(head);
    return;
}