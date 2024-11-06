#include<stdio.h>

int gcd(int a,int b){
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    else
        return gcd(a,b-a);
}

int main(){
    int a=60;
    int b= 36;
    int x= gcd(a,b);
    printf("%d",x);
}

