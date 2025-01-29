/*Program to convert infix expression to postfix
Author:- Ishank Kumar
Date:- 28-09-2024
*/

/*preprocessor directories*/
#include<stdio.h>
#include<string.h>
#define SIZE 100

/*Function definitions*/
int fnPrecedence(char);
char fnAssociativity(char);
void fnInfixToPostfix(char[]);

int main(void)
{
    char infix[SIZE];
    printf("Enter the infix expression\n");
    scanf("%s",infix);    
    fnInfixToPostfix(infix);
    return 0;
}

// Function to determine the precedence of operators
int fnPrecedence(char symbol){
    if(symbol=='^'||symbol=='$')
        return 3;
    else if (symbol=='*'||symbol=='/' )
        return 2;
    else if(symbol=='+'||symbol=='-')
        return 1;
    return -1;
}

// Function to determine the associativity of operators
char fnAssociativity(char symbol){
    if (symbol=='^'|| symbol=='$')
        return 'R'; // Right associative
    return 'L'; // Left associative
}

// Function to convert infix expression to postfix
void fnInfixToPostfix(char s[]){
    char symbol;
    char postfixIndex = 0;
    char postfix[SIZE];
    char stack[SIZE];
    char stackIndex= -1;
    int i;
    int length = strlen(s);
    for(i=0;i<length;i++){
        symbol=s[i];

        // If the symbol is an operand, add it to the postfix expression
        if(symbol>='a'&&symbol<='z'||symbol>='A'&&symbol<='Z'||symbol>='0'&&symbol<='9'){
            postfix[postfixIndex++]=symbol;
        }
        // If the symbol is '(', push it to the stack
        else if(symbol=='('){
            stack[++stackIndex]=symbol;
        }
        // If the symbol is ')', pop and output from the stack until '(' is found
        else if(symbol==')')
        {
            while(stackIndex>=0 && stack[stackIndex]!='(')  {
                postfix[postfixIndex++]=stack[stackIndex--];
            }
            stackIndex--; // pop '('
        }
        // If the symbol is an operator
        else{
            while((stackIndex>=0)&&fnPrecedence(symbol)<=fnPrecedence(stack[stackIndex])&&fnAssociativity(symbol)=='L')
            {
                postfix[postfixIndex++]=stack[stackIndex--];
            }
            stack[++stackIndex] = symbol;
        }
    } // End of Scanning

    // Pop all the operators from the stack
    while(stackIndex!=-1){
        postfix[postfixIndex++]=stack[stackIndex--];
    }

    postfix[postfixIndex]='\0'; // Null terminate the postfix expression
    printf("Infix expression: %s\nPostfix expression: %s\n", s, postfix);
}