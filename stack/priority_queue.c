#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct pqueue{
    int A[SIZE];
    int front;
    int rear;
};

typedef struct pqueue PQUEUE;

void fnInsert(PQUEUE *q,int item);
void fnDelete(PQUEUE *q);
void fnDisplay(PQUEUE *q);

void fnInsert(PQUEUE *q,int item){
    if(q->rear==SIZE-1){
        printf("Queue is full");
        return;
    }

    int j=q->rear;
    while(j>=0&&item<q->A[j]){
        q->A[j+1]=q->A[j];
        j--;
    }
    q->A[j+1]=item;
    q->rear++;
}

void fnDelete(PQUEUE *q){
    printf("Delete element is %d",q->A[q->front++]);
    return;
}

void fnDisplay(PQUEUE *q){
    if(q->front>q->rear){
        printf("Queue underflow");
        return;
    }

    for(int i=q->front;i<=q->rear;i++){
        printf("%d\n",q->A[i]);
        
    }
}

void main(){
    PQUEUE q;
    q.front=0;
    q.rear=-1;
    fnInsert(&q,1);
    fnInsert(&q,2);
    fnInsert(&q,3);
    fnInsert(&q,4);
    fnDisplay(&q);
    fnDelete(&q);
    fnDisplay(&q);
}