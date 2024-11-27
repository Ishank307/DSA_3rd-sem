// program to implement normal integer stack
// author Ishank Kumar

#include<stdio.h>
#include<stdlib.h>
# define SIZE 5
/*Stack specification*/

struct stack {
    int A[SIZE];
};

typedef struct stack STACK;

/*Fuction prototypes*/

void fnPush(STACK*,int);
int fnPop(STACK*);
int fnIsFull(STACK);
int fnIsEmpty(STACK);
int fnPeek(STACK);

int main(){
    // create stack
    STACK s;

    int iElement,ipeek,ichoice,iPoppedElement;
    for(;;){
        printf("1:Push\n2:Pop\n3:Peek\n4:exit\n");
        printf("Enter the choice");
        scanf("%d",&ichoice);

        switch(ichoice){
            case 1: printf("Enter the element to be pushed");
                    scanf("%d",&iElement);
                    fnPush(&s,iElement);
                    break;
            case 2: iPoppedElement=fnPop(&s);
                    printf("Popped Element is %d\n",iPoppedElement);
                    break;
            case 3: ipeek=fnPeek(s);
                    printf("peek Element is %d \n",ipeek);
                    break;
            case 4: printf("Thank You \n");
                    Exit(0);
            default: printf("Invalid Choice\n");
                    printf("Please reenter your choice \n");
                    break;
        }       /*closure switch*/

    }
    
}

void fnPush(STACK *s,int n ){
    if fnIsFull(s)
}
