#include <stdio.h>

int main(){

   int mat1[10][10];
   int mat2[10][10];
   int mat3[10][10];
   int row1 = 4, col1= 3, row2 = 3, col2 = 6;
   int i,j,k;

   //Matriks 4 x 3
   for(i=0; i<row1 ; i++){
      for(j=0; j<col1; j++){
         scanf("%d", &mat1[i][j]);
      }
   }
   
   
   //Matriks 3 x 6
   for(i=0; i<row2; i++){
      for(j=0; j<col2; j++){
         scanf("%d", &mat2[i][j]);
      }
   }

   //Perkalian Matriks
   for(i=0; i<row1; i++){
      for(j=0; j<col2; j++){
         for(k=0; k<col1; k++){
            mat3[i][j] = mat1[i][k] * mat2[k][j];
         }
      }
   }
   
   //Print Hasil
   for(i=0; i<row1; i++){
      for(j=0; j<col2; j++){
         printf("[%d] ", mat3[i][j]);
         if(j==col2-1){
            printf("\n");
         }
      }
   }

}
