#include<stdio.h>
#include<string.h>
#include<ctype.h>

double compute(double op1, double op2,char symbol){
    switch(symbol){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': 
            if(op2 != 0) return op1 / op2;
            else {
                printf("Error: Division by zero.\n");
                return 0; // Handle division by zero
            }
        case '^': return pow(op1, op2); // Exponentiation
        case '$': return (int)op1 % (int)op2; // Modulus
        default:
            printf("invalid operator");
            
    }
}

int main(){
    char postfix[200];
    char symbol;
    int i;
    double s[200],op1,op2,result;
    int top=-1;
    printf("Enter the valid postfix expression");
    scanf("%s",postfix);
    for(i=0;i<strlen(postfix);i++){
        symbol = postfix[i];
        if (isdigit(symbol))
        {
            s[++top]=symbol-'0';
        }
        else{
            op2=s[top--];
            op1=s[top--];
            result=compute(op1,op2,symbol);
        }
    }
    result=s[top];
    printf("%lf",result);
    return 0;
}


