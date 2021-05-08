#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

int mat1[10][10];
int mat2[10][10];
int mat3[10][10];
int row1 = 4, col1= 3, row2 = 3, col2 = 6;
pthread_t tid[10];

//Matriks 4 x 3
void *num_mat1(void *arg){
   int i,j;
   for(i=0; i<row1; i++){
      for(j=0; j<col1; j++){
         scanf("%d", &mat1[i][j]);
      }
   }
}

//Matriks 3 x 6
void *num_mat2(void *arg){
   int i,j;
   for(i=0; i<row2; i++){
      for(j=0; j<col2; j++){
         scanf("%d", &mat2[i][j]);
      }
   }
}

//Perkalian
void *calculate(void *arg){
   int i,j,k;
   for(i=0; i<row1; i++){
      for(j=0; j<col2; j++){
         for(k=0; k<col2; k++){
            mat3[i][j] = mat1[i][k] * mat2[k][j];
         }
      }
   }
}

//Print Hasil
void *print_result(void *arg){
   int i,j;
   for(i=0; i<row1; i++){
      for(j=0; j<col2; j++){
         printf("[%d] ", mat3[i][j]);
         if(j==col2-1){
            printf("\n");
         }
      }
   }
}

int main(){

   key_t key = 1234;
   int shmid = shmget(key, sizeof(int[10][10]), IPC_CREAT | 0666);
   value shmat(shmid,0,0);


   pthread_create(&(tid[0]),NULL,num_mat1,NULL);
   pthread_join(tid[0],NULL);

   pthread_create(&(tid[1]),NULL,num_mat2,NULL);
   pthread_join(tid[1],NULL);
   
   pthread_create(&(tid[2]),NULL,calculate,NULL);
   pthread_join(tid[2],NULL);

   pthread_create(&(tid[3]),NULL,print_result,NULL);
   pthread_join(tid[3],NULL);
   

}
