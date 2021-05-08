#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

int mat[10][10];
int row=4, col=6;


void make_mat(){
    int i,j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

