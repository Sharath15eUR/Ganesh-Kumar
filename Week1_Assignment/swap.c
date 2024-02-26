#include<stdio.h>

void swap( int *num1, int *num2){
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

int main(){
    // function pointer for swapping
    void (*swapFunction)(int*, int*);
    swapFunction = swap;

    int a,b;
    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);

    printf("\nBefore Swapping\ta: %d\tb:%d",a,b);

    swapFunction(&a,&b);

    printf("\nAfter Swapping\ta: %d\tb:%d",a,b);

}