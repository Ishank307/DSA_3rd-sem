#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
struct Node {
    char data;
    struct Node* next;
};
typedef struct Node* STACK;

// Function to create a new node
STACK getNode(char data) {
    STACK temp = (STACK)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to push a character onto the stack
STACK push(STACK head, char data) {
    STACK temp = getNode(data);
    temp->next = head;
    head = temp;
    return head;
}

// Function to pop a character from the stack
STACK pop(STACK head, char* poppedData) {
    if (head == NULL) {
        *poppedData = '\0'; // Return null character if the stack is empty
        return NULL;
    }
    STACK temp = head;
    *poppedData = temp->data;
    head = head->next;
    free(temp);
    return head;
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    STACK head = NULL;
    int len = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++) {
        head = push(head, str[i]);
    }

    // Pop characters from the stack and compare with the original string
    for (int i = 0; i < len; i++) {
        char poppedChar;
        head = pop(head, &poppedChar);
        if (poppedChar != str[i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Main function
int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

return 0;
}
