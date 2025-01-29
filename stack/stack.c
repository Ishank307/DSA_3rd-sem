//c program to implement stack 
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct stack {
    int a[SIZE];
    int top;
};
typedef struct stack STACK;

// Check if the stack is full
int isFull(STACK *s) {
    return s->top == SIZE - 1;
}

// Check if the stack is empty
int isEmpty(STACK *s) {
    return s->top == -1;
}

// Push an element to the stack
void fnPush(STACK *p, int item) {
    if (isFull(p)) {
        printf("Stack overflow\n");
        return;
    }
    p->top = p->top + 1;
    p->a[p->top] = item;
}

// Pop an element from the stack
int fnPop(STACK *p) {
    if (isEmpty(p)) {
        printf("Stack underflow\n");
        return -1;  // Return -1 to indicate stack is empty
    }
    return p->a[p->top--];
}

// Peek the top element of the stack
void fnPeek(STACK *p) {
    if (isEmpty(p)) {
        printf("Stack underflow\n");
        return ;  // Return -1 to indicate stack is empty
    }
    printf("Peeked element is %d\n",p->a[p->top]);
}

// Display elements of the stack
void display(STACK *p) {
    if (isEmpty(p)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = p->top; i >= 0; i--) {
        printf("%d ", p->a[i]);
    }
    printf("\n");
}

int main(void) {
    STACK s;
    s.top = -1;  // Initialize the stack
    int iElement, iChoice, iPoppedElement, iPeek;

    for (;;) {
        printf("1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &iChoice);

        switch (iChoice) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &iElement);
                fnPush(&s, iElement);
                break;

            case 2:
                iPoppedElement = fnPop(&s);
                if (iPoppedElement != -1) {
                    printf("Popped element is: %d\n", iPoppedElement);
                }
                break;

            case 3:
                fnPeek(&s);
                break;

            case 4:
                display(&s);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
    }