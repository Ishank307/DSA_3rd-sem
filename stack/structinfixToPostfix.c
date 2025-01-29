#include <stdio.h>
#include <string.h>
#define max_size 10

struct infixtopost
{
 int top;
 char stack[max_size];
};
typedef struct infixtopost INFIX;

void infix_postfix(INFIX * ,char [] ,char []);
int F(char symbol);
int G(char symbol);

int main()
{
 INFIX s;
 s.top=-1;
 char infix[max_size],postfix[max_size];
 printf("Enter the expresion of infix:");
 scanf("%s",infix);
 infix_postfix(&s, infix, postfix);
 printf("%s",postfix);
 return 0;
}

void infix_postfix(INFIX *s,char infix[],char postfix[])
{
  char symbol;
   int j=0,i;
   s->stack[++(s->top)]='#';
   for (i=0;i<strlen(infix);i++)
   {
    symbol=infix[i];
    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'))
    {
        postfix[j++] = symbol;
    }

    else if (symbol == '(')
    {
      s->stack[++(s->top)] = symbol;
    }

    else if (symbol == ')')
    {
        while (s->stack[s->top]!='(')
        {
            postfix[j++] = s->stack[(s->top)--];
        }
        s->top--;   // '(' will be ignored---
    }

    else
    {
        while (F(s->stack[s->top]) >= G(symbol))
        {
            postfix[j++] = s->stack[(s->top)--];
        }
    s->stack[++(s->top)] = symbol;
    }
 }

 while (s->stack[(s->top)]!= '#') // pop all the remaining operators to postfix
{
    postfix[j++] = s->stack[(s->top)--];
}
postfix[j] = '\0';
}


int F(char symbol)
{
switch(symbol)
{
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 4;
    case '^':
    case '$': return 5;
    case '(': return 0;
    case '#': return -1;
    default: return 8;
}
}

int G(char symbol)
{
switch(symbol)
{
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 3;
    case '^':
    case '$': return 6;
    case '(': return 9;
    case ')': return 0;
    default: return 10;
}
}