#include<stdio.h>

// count the number of set bits (1's)

//display the number in binary
void bin(unsigned int n){
    
    printf("\n%u : ",n);
    for(int i=((8*sizeof(n))-1);i>=0;i--){
        printf("%d",n>>i & 1);
    }
}

int main(){
    unsigned int num,count=0;

    printf("\nEnter the Number : ");
    scanf("%u",&num);
    bin(num);

    for(int i=31;i>=0;i--){
        if((num>>i & 1)== 1) count++;
    }
    printf("\nThe Number of set bits : %u",count);

}

