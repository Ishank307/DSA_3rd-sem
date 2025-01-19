#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink, *rlink;
};
typedef struct node* NODE;

NODE getnode() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return temp;
}

NODE fnInsertfront(NODE head, int item) {
    NODE temp, curr;
    temp = getnode();
    temp->info = item;
    curr = head->rlink;
    temp->rlink = curr;
    curr->llink = temp;
    head->rlink = temp;
    temp->llink = head;
    return head;
}

NODE fnInsertrear(NODE head, int item) {
    NODE curr, temp;
    temp = getnode();
    temp->info = item;
    curr = head->llink;
    curr->rlink = temp;
    temp->llink = curr;
    temp->rlink = head;
    head->llink = temp;
    return head;
}

NODE fnDeletefront(NODE head) {
    NODE temp, curr;
    if (head->rlink == head) {
        printf("List is empty\n");
        return head;
    }
    curr = head->rlink;
    temp = curr->rlink;
    head->rlink = temp;
    temp->llink = head;
    printf("Deleted element is %d\n", curr->info);
    free(curr);
    return head;
}

NODE fnDeleterear(NODE head) {
    NODE temp, curr;
    if (head->llink == head) {
        printf("List is empty\n");
        return head;
    }
    curr = head->llink;
    temp = curr->llink;
    temp->rlink = head;
    head->llink = temp;
    printf("Deleted element is %d\n", curr->info);
    free(curr);
    return head;
}

void display(NODE head) {
    NODE curr;
    if (head->rlink == head) {
        printf("List is empty\n");
        return;
    }
    curr = head->rlink;
    while (curr != head) {
        printf("%d\n", curr->info);
        curr = curr->rlink;
    }
}

void main(void) {
    NODE head;
    head = getnode();
    head->info = 0;
    head->llink = head->rlink = head;

    head = fnInsertfront(head, 8);
    head = fnInsertfront(head, 10);
    head = fnInsertfront(head, 18);
    head = fnDeletefront(head);
    head = fnInsertrear(head, 30);

    display(head);
}