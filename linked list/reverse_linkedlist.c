#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * fnReverse_list(struct node * first){
    struct node *curr,*prev,*next;
    curr=first;
    next=NULL;
    prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}



main(){

}