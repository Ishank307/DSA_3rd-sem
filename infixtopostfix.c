/*Program to convert infix expression to postfix
Author:- Ishank Kumar
Date:- 28-09-2024
*/
#include<stdio.h>
#include<string.h>
#define SIZE 100

int fnPrecedence(char);
char fnAssociativity(char);
void fnInfixToPostfix(char[]);

int main(void)
{
    char infix[]="a+b-c*(d^f)-e";
    fnInfixToPostfix(infix);
    return 0;
}

int fnPrecedence(char symbol){
    if(symbol=='^'||symbol=='$')
        return 3;
        else if (symbol=='*'||symbol=='/' )
            return 2;
            else if(symbol=='+'||symbol=='-')
                return 1;
            
}

char fnAssociativity(char symbol){
    if (symbol=='A'|| symbol=='$')
    return 'R';
    return 'L';
}

void fnInfixToPostfix(char s[]){
    char symbol;
    char postfixIndex = 0;
    char postfix[SIZE];
    char stack[SIZE];
    char stackIndex= -1;
    int i;
    int length = stlen(s);
        for(i=0;i<length;i++){
            symbol=s[i];

        /*operand*/

        if(c>=)
        
    }

}