#include "matrix.h"
#include <stdio.h>



Matrix create_matrix(int rows, int cols){
    Matrix matrix;
    matrix.row = rows;
    matrix.col = cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix.data[i][j] = 0.0;
        }
        
    }
    return matrix;
    
}


void set(Matrix *matrix, int row, int col, double value){
    matrix -> data[row][col] = value;
}


double get(Matrix *matrix, int row, int col){
    return matrix -> data[row][col];
}



void print_matrix(Matrix *matrix){
    
    for (int i = 0; i < matrix -> row; i++)
    {
        printf("[");
        for (int j = 0; j < matrix -> col; j++)
        {
            if(j == matrix -> col - 1){
                printf("%.1lf", matrix -> data[i][j]);
                continue;

            }
            printf("%lf, ", matrix -> data[i][j]);
        }
        printf("]\n");

        
    }
    
}


int main(){


    Matrix a = create_matrix(2, 2);
    set(&a,0,0,1);
    set(&a,0,1,2);
    set(&a,1,0,3);
    set(&a,1,1,4);
    print_matrix(&a);
    return 0;
}

