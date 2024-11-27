/*program to convert infix to postfix using structures
Author:- Ishank Kumar
Date:-29-09-2024
*/

/*preprocessor dirctories*/

#include<stdio.h>
#include<string.h>
#define SIZE 5

/*structure part*/
struct stack{
    char A[SIZE];
    int top;
};

typedef struct stack STACK;

/*Function definitions*/
int fnPrecedence(char);
char fnAssociativity(char);
char fnInfixToPostfix(char*,char*);

/*Function name:- Main
  Function type:- int
  return type:- 0
  Author:- Ishank Kumar
  */

int main(void){
    STACK s;
    char infix[SIZE],postfix[SIZE];
    printf("Enter the string :-\n");
    scanf("%s",infix);
    fnInfixToPostfix(infix,postfix);
    return 0;
}
/*Function type :- int
  Return type:- integers 1,2,3,-1
  Author:- Ishank Kumar
*/

int fnPrecedence(char symbol){
    if(symbol=='^'||symbol=='$')
    return 3;
        else if(symbol=='*'||symbol=='/')
        return 2;
            else if(symbol=='+'||symbol=='-')
            return 1;
    return -1;

}

/*Function type :- char
  Return type:- characters R or L
  Author:- Ishank Kumar
  Dtae:-29-09-2024
*/

char fnAssociativity(char symbol){
    if(symbol=='^'||symbol=='$')
    return 'R';
    return 'L';
}

char fnInfixToPostfix(char* infix,char*postfix){
    STACK s;
    s.top=-1;
    int i=0,j=0;

    while (infix[i]!='\0'){
      char symbol = infix[i];

      /*operator */
      if((symbol >='A' && symbol <='Z')||(symbol>='a'&&symbol<='b')||(symbol>='0'&&symbol<='9')){
        postfix[j++]=symbol;
      }
      else if(symbol=='('){
        s.A[++s.top]=symbol
      }
    

    }
     
}