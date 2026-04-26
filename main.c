#include <stdio.h>
#include "matrix.h"

// declare functions from your regression file
Matrix predict(Matrix *weights, Matrix *X, Matrix *bias);
double cost(Matrix *predicted_values, Matrix *true_labels);
void train(Matrix *X, Matrix *true_labels, Matrix *weights, Matrix *bias, double learning_rate, int epochs);

int main() {


// ===== 1. Create dataset =====
// y = 2x

Matrix X = create_matrix(4, 1);
Matrix y = create_matrix(4, 1);

// Fill X
set(&X, 0, 0, 1);
set(&X, 1, 0, 2);
set(&X, 2, 0, 3);
set(&X, 3, 0, 4);

// Fill y
set(&y, 0, 0, 2);
set(&y, 1, 0, 4);
set(&y, 2, 0, 6);
set(&y, 3, 0, 8);

// ===== 2. Initialize parameters =====

Matrix W = create_matrix(1, 1);   // 1 feature → 1 weight
Matrix b = create_matrix(1, 1);   // bias as 1x1 matrix

set(&W, 0, 0, 0.0);
set(&b, 0, 0, 0.0);

// ===== 3. Train =====

double learning_rate = 0.01;
int epochs = 10000;

train(&X, &y, &W, &b, learning_rate, epochs);

// ===== 4. Print learned parameters =====

printf("\nLearned weights:\n");
print_matrix(&W);

printf("Learned bias:\n");
print_matrix(&b);

// ===== 5. Test prediction =====

Matrix X_test = create_matrix(1, 1);
set(&X_test, 0, 0, 5);   // x = 5

Matrix y_pred = predict(&W, &X_test, &b);

printf("\nPrediction for x = 5:\n");
print_matrix(&y_pred);

return 0;


}
