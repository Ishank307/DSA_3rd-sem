#include<stdio.h>

// Function prototype for fib
int fib(int n);

int main(){
    int i, n;
    printf("Enter n\n");
    scanf("%d", &n);

    printf("%d Fibonacci numbers are \n", n);
    for(i = 0; i < n; i++){
        printf("fib(%d) = %d\n", i, fib(i));
    }
}

// Function to calculate the nth Fibonacci number
int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}