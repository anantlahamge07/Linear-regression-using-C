# Linear Regression from Scratch in C

## Overview

This project implements **Linear Regression from scratch in C**, without using any external libraries.

It includes:

* A custom matrix library
* Gradient descent optimization
* Support for multiple features (generalized model)

The goal of this project is to understand how machine learning works **under the hood**, by building everything from first principles.

---

## Features

* Matrix operations:

  * Creation
  * Multiplication
  * Addition & subtraction
  * Transpose
  * Scalar multiplication

* Linear Regression:

  * Prediction: "`y = XW + b`"
  * Cost function (Mean Squared Error)
  * Gradient computation
  * Parameter updates using Gradient Descent

* Supports:

  * Single feature regression
  * Multi-feature regression

---

## Project Structure

```
.
├── matrix.h
├── matrix.c
├── LinearRegression.h
├── LinearRegression.c
├── main.c
```

---

## How it works

The model learns the relationship:

```
ŷ = XW + b
```

Where:

* `X` = input features
* `W` = weights
* `b` = bias

The model minimizes the cost:

```
J = (1 / 2n) * Σ (ŷ - y)^2
```

using **Gradient Descent**:

```
W := W - α * dW
b := b - α * db
```

---

## Compilation & Run

```bash
gcc main.c matrix.c LinearRegression.c -o program
./program
```

---

## Example

### Input (multi-feature)

```
X = [[1, 2],
     [2, 1],
     [3, 4],
     [4, 3]]

y = [[8],
     [7],
     [18],
     [17]]
```

### Output

```
Learned weights:
[2.0]
[3.0]

Learned bias:
[0.0]
```

### Prediction

```
Input: [5, 2]
Output: 16
```

---

## Key Learnings

* Implemented linear algebra operations manually
* Understood how gradient descent works step-by-step
* Learned how numerical stability and learning rate affect training
* Built a generalized ML model in a low-level language

---

## Limitations

* Fixed-size matrices (no dynamic memory allocation)
* No feature scaling (important for real-world data)
* No regularization

---

## Future Improvements

* Dynamic memory allocation for matrices
* Feature normalization
* Logistic regression (classification)
* Neural network implementation

---

## Author

Anant Anil Lahamge

---

## License

This project is open-source and available under the MIT License.
