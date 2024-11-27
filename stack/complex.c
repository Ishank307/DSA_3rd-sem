#include <stdio.h>

struct complex{         //Structure for Complex
    int real;
    int imaginery;
};

typedef struct complex COMPLEX;

void fnAddComplex(COMPLEX*,COMPLEX*);   //Add function Declaration
void fnSubComplex(COMPLEX*,COMPLEX*);   //Substract function declaration
void readComplex(COMPLEX*,COMPLEX*);    //read function declaration

int main(){
    COMPLEX c1,c2;
    readComplex(&c1,&c2);
    fnAddComplex(&c1,&c2);
    fnSubComplex(&c1,&c2);
    return 0;
}

void readComplex(COMPLEX* c1,COMPLEX* c2){
    printf("ENter the first complex number real and imaginery parts");
    scanf("%d %d",&c1->real,&c1->imaginery);
     printf("ENter the second complex number real and imaginery parts");
    scanf("%d %d",&c2->real,&c2->imaginery);
}

void fnAddComplex(COMPLEX* c1,COMPLEX* c2){
    COMPLEX c3;
    c3.real=c1->real+c2->real;
    c3.imaginery=c1->imaginery+c2->imaginery;
    printf("The sum is complex is %d+%di\n",c3.real,c3.imaginery);

}

void fnSubComplex(COMPLEX* c1,COMPLEX* c2){
    COMPLEX c3;
    c3.real=c1->real-c2->real;
    c3.imaginery=c1->imaginery-c2->imaginery;
    printf("The sub is complex is %d+%di\n",c3.real,c3.imaginery);

}
