#include<stdio.h>
#include<stdlib.h>

/* C program for implementation of binary tree
    Author
*/

struct node {
    struct node * llink;
    struct node * rlink;
    int info;
};

typedef struct node * NODE;

NODE getnode(){
    NODE temp;

    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Malloc failed");
        return NULL;
    }
    return temp;
}

NODE fnInsert(NODE root,int item){
    NODE curr,next,prev,temp;
    temp= getnode();
    temp->info=item;
    temp->rlink=temp->llink=NULL;
    if(root==NULL)
        return temp;
    prev=NULL;
    curr=root;
    while(curr!=NULL){
    prev=curr;
    if(item==curr->info)
    {
        printf("Duplicates are not allowed");
        free(temp);
        return root;
    }
    if(item<curr->info)
        curr=curr->llink;
    else 
        curr=curr->rlink;
    }
    if (item < prev->info)
        prev->llink=temp;
    else 
        prev->rlink=temp;
    
    return root;

}

void preorder(NODE root){
    if(root==NULL)
    return;
    printf("%d ",root->info);
    preorder(root->llink);
    preorder(root->rlink);
    return;
}

void inorder(NODE root){
    if(root==NULL)
    return;
    inorder(root->llink);
    printf("%d ",root->info);
    inorder(root->rlink);
    return;
}

void postorder(NODE root){
    if(root==NULL)
    return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ",root->info);
    return;
}


int main(){

    NODE root=NULL;
    int ichoice,element;
    for(;;){
        printf("Enter the choice\n 1.INSERT\n2.preorder\n");
        scanf("%d",&ichoice);
        switch(ichoice){
            case 1: printf("Enter the element to be inserted");
                    scanf("%d",&element);
                    root=fnInsert(root,element);
                    break;
            case 2: preorder(root);
                    break;
            case 3: inorder(root);
                    break;
            case 4: postorder(root);
                    break;            
            default: printf("Invalid");
                     exit(0);
        }

    }
    return 0;
}

