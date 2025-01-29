#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100

int fnPrecedence(char symbol){
    if(symbol=='$'||symbol=='^')
        return 3;
    else if(symbol=='*'||symbol=='/')
        return 2;
    else if (symbol=='+'||symbol=='-')
        return 1;
    return -1;
}

char fnAssociativity(char symbol)
{
    if(symbol=='$'||symbol=='^')
        return 'R';
    return 'L';
}

void infixToPostfix(char s[]){
    char postfix[SIZE];
    char stack[SIZE];
    int postfixIndex = 0; 
    int stackIndex= -1;
    int i;
    char symbol;
    for (i=0;i<strlen(s);i++){
        symbol=s[i];
        if(symbol>='a'&&symbol<='z'||symbol>='A'&&symbol<='Z'||symbol>='0'&&symbol<='9')
            postfix[postfixIndex]=symbol;
        else if()


    }
}