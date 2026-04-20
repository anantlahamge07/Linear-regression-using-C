#pragma once
#include <stdio.h>
#include "matrix.h"


Matrix predict(Matrix *weights, Matrix *X, Matrix *bias);


double cost(Matrix *predicted_values, Matrix *true_labels);


void compute_gradients(Matrix *X, Matrix *weights, Matrix *dW, Matrix *db, Matrix *bias, Matrix *y_true);


void update_parameters(Matrix *weights, Matrix *bias, Matrix *dW, Matrix *db, double learning_rate);


void train(Matrix *X, Matrix *true_labels, Matrix *weights, Matrix *bias, double leaarning_rate, int epochs);