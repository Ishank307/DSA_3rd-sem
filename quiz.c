#include <stdio.h>

int main(){

int arr[10]; // arr is initialised with some ten integers
int out[10];   // this is the array where we store those unique elements
int count=0;
for (int i = 0; i < 10; i++)

{
    int j=0;
    for (; j < 10; j++) // for each array element we are searching for duplicates
    {
        if (i != j && arr[i] == arr[j])
        {
        }
        break; // if we find a duplicate, we need not continue the loop }
        if ((j==10))
        {
            out[count] = arr[i];
            count++;
        }
    }
    for (int k = 0; (k,count); k++)
        printf("%d", out[k]);
    return 0;
}
}