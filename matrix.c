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

Matrix product(Matrix *m1, Matrix *m2){
    Matrix result;
    result.row = m1 -> row;
    result.col = m2 -> col;

    for (int i = 0; i < result.row; i++)
    {
        for (int j = 0; j < result.col; j++)
        {
            result.data[i][j] = 0.0;
        }
        
    }
    
    for (int i = 0; i < m1 -> row; i++)
    {
        for (int j = 0; j < m2 -> col; j++)
        {
            for (int k = 0; k < m1 -> col; k++)
            {
                result.data[i][j] += (m1 -> data[i][k])* (m2 -> data[k][j]);
            }
            
        }
        
    }
    return result;
}


Matrix add(Matrix *m1, Matrix *m2){
    Matrix result;
    result.row = m1 -> row;
    result.col = m1 -> col;
    for (int i = 0; i < m1 -> row; i++)
    {
        for (int j = 0; j < m1 -> col; j++)
        {
            result.data[i][j] = (m1 -> data[i][j]) + (m2 -> data[i][j]);
            
        }
        
    }
    return result;
}

Matrix sub(Matrix *m1, Matrix *m2){
    Matrix result;
    result.row = m1 -> row;
    result.col = m1 -> col;
    for (int i = 0; i < m1 -> row; i++)
    {
        for (int j = 0; j < m1 -> col; j++)
        {
            result.data[i][j] = (m1 -> data[i][j]) - (m2 -> data[i][j]);
            
        }
        
    }
    return result;
}
Matrix transpose(Matrix *m){
    Matrix result;
    result.row = m -> col;
    result.col = m -> row;
    for (int i = 0; i < m-> row; i++)
    {
        for (int j = 0; j < m -> col; j++)
        {
            result.data[j][i] = m -> data[i][j];
            
        }
        
    }
    return result;
}


Matrix scalar_multiply(Matrix *m, double scalar){
    Matrix result;
    result.row = m -> row;
    result.col = m -> col;
    for (int i = 0; i < m -> row; i++)
    {
        for (int j = 0; j < m -> col; j++)
        {
            result.data[i][j] = scalar*(m -> data[i][j]) ;
            
        }
        
    }
    return result;
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


