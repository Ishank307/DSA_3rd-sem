#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct node
{
        char info;
        struct node *rlink;
        struct node *llink;
};

typedef struct node * NODE;
NODE fnGetNode()
{
        NODE temp;
        temp=(NODE)malloc(sizeof(struct node));
        return temp;
}

NODE fnCreate_ExpTree(char *postfix)
{
        NODE temp,STACK[30];
        char symbol;
        int k=-1,i;
        for(i=0;postfix[i]!='\0';i++)
        {
                symbol=postfix[i];
                temp=fnGetNode();
                temp->info=symbol;
                temp->llink=NULL;
                temp->rlink=NULL;
                if(isalnum(symbol))
                {
                        STACK[++k]=temp;
                }
                else
                {
                        temp->rlink=STACK[k--];
                        temp->llink=STACK[k--];
                        STACK[++k]=temp;
                }
        }
        return STACK[k--];
}

float fnEvaluate(NODE root)
{
        float num;
        switch(root->info)
        {
                case '+':return (fnEvaluate(root->llink) + fnEvaluate(root->rlink));
                case '-':return (fnEvaluate(root->llink) - fnEvaluate(root->rlink));
                case '*':return (fnEvaluate(root->llink) * fnEvaluate(root->rlink));
                case '/':return (fnEvaluate(root->llink) / fnEvaluate(root->rlink));
                case '$':
                case '^':return pow(fnEvaluate(root->llink),fnEvaluate(root->rlink));
                default:if(isalpha(root->info))
                        {
                                printf("Enter the value of  %c :",root->info);
                                scanf("%f",&num);
                                return num;
                        }
                        else
                                return root->info -'0';
        }
}

int main()
{
        float result;
        NODE root;
        char postfix[30];
        printf("Enter a valid postfix expression : ");
        scanf("%s",postfix);
        root=fnCreate_ExpTree(postfix);
        result=fnEvaluate(root);
        printf("RESULT : %0.3f\n",result);
        return 0;
}
