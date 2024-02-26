#include<stdio.h>

// odd or even using bitwise operation
int main(){

    int num;
  
    printf("\nEnter the Number : ");
    scanf("%d",&num);

    if(num & 1 == 1)
        printf("The Number %d is Odd ",num);
    else
        printf("The Number %d is Even ",num);
    return 0;
}

