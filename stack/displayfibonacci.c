#include<stdio.h>


int main(){
    int i,n;
    printf("Enter n\n");
    scanf("%d",&n);

    printf("%d Fibonacci numbers are \n",n);
    for(i=0;i<n;i++){
        {
        printf("fib(%d)=%d\n",i,fib(i));
        }
    }
}

int fib(int n){
    if (n==0) return 0;
    
    if (n==1) return 1;

    return fib(n-1) +fib(n-2);
}