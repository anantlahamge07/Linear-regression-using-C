#pragma once
#include <stdio.h>


typedef struct {
    int row;
    int col; 
    double data[100][100];
} Matrix;

//Function declarations

Matrix create_matrix(int row, int cols);

void set(Matrix *matrix, int row, int cols, double value);

double get(Matrix *matrix, int row, int col);

void print_matrix(Matrix *matrix);

Matrix product(Matrix *m1, Matrix *m2);

Matrix add(Matrix *m1, Matrix *m2);

Matrix transpose(Matrix *m);

Matrix sub(Matrix *m1, Matrix *m2);

Matrix scalar_multiply(Matrix *m, double scalar);






