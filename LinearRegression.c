
#include <stdio.h>
#include "matrix.h"

typedef struct{
    Matrix dw;
    Matrix db;

}Tuple;

Matrix predict(Matrix *weights, Matrix *X, Matrix *bias){
    Matrix mul = product(X, weights);
    Matrix predictions = add(&mul, bias);
    return predictions;
}

double cost(Matrix *predicted_values, Matrix *true_labels){
    double n = predicted_values -> row;
    double summation = 0.0;

    for (int i = 0; i < n; i++)
    {
        summation += (predicted_values -> data[i][0] - true_labels -> data[i][0])*(predicted_values -> data[i][0] - true_labels -> data[i][0]);
    }
    return (summation)/(2*n);
}
// now this is where it gets actually interesting. It's actually easy to comprehend, if you understand how the gradients are getting computed for weights and for the bias :)

Tuple compue_gradients(Matrix *X, Matrix *weights, Matrix *bias, Matrix *true_labels){
    //just to make it clear the gradient for weights will be calculated using ∂J/∂W=(1/n)*X^T*(y^​−y)
    //and the gradients for bais will be calculated using ∂J/∂b​=(1/n)​∑(y^​−y)
    Matrix y_hat = predict(weights, X, bias);
    Matrix error = sub(&y_hat, true_labels);
    Matrix X_T = transpose(X);
    Matrix mul = product(&X_T, &error);
    Matrix dW = scalar_multiply(&mul, (1/(true_labels -> row))); // n ist here the no. of samples, which we get from the no. of rows in our true_values
    double summation = 0.0;
    for (int i = 0; i < error.row; i++)
    {
        summation += error.data[i][0];
    }
    Matrix db;
    db.row = 1;
    db.col = 1;
    db.data[0][0] = (1/(true_labels -> row))*summation;
    Tuple tuple;
    tuple.dw = dW;
    tuple.db = db;
    return tuple;
}


void update_paramaters(Matrix *weights, Matrix *bias, Matrix *dW, Matrix *db, double learning_rate){
    
    Matrix m1 = scalar_multiply(dW, learning_rate);
    Matrix m2 = scalar_multiply(db, learning_rate);
    *weights = sub(&weights, &m1);
    *bias = sub(&bias, &m2);

}




