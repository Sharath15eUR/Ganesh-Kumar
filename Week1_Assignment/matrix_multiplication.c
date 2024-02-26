#include<stdio.h>

void write_matrix(int row,int column,int *array){
    for(int i=0;i<row*column;i++)
        scanf("%d",array+i);
}

void print_matrix(int row,int column,int *array){
    for(int i=0;i<row;i++){
        printf("\n");
        for(int j=0;j<column;j++)
            printf("%d ",*(array+(i*column)+j));
    }
}
void mat_mul(int *array1,int *array2,int *res){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            *(res+(i*3)+j)=0;
            for(int k=0;k<3;k++){
                *(res+(i*3)+j) += *(array1+(i*3)+k)*(*(array2+(k*3)+j));
            }
        }
    }
}
int main(){

     int row,column,mat1[3][3],mat2[3][3],res[3][3];
     
     printf("Size of Row : ");
     scanf("%d",&row);
     printf("Size of Column : ");
     scanf("%d",&column);
     
     printf("Matrix 1:\n");
     write_matrix(row,column,*mat1);
     printf("Matrix 2:\n");
     write_matrix(row,column,*mat2);

     printf("\nProduct:");
     mat_mul(*mat1,*mat2,*res);
     print_matrix(row,column,*res);
    

}

