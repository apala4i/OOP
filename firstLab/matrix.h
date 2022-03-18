#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

#define MATRIX_SIZE_ERROR 1
#define MATRIX_INPUT_ERROR 2

typedef struct Matrix Matrix;
struct Matrix
{
    std::vector<std::vector<double>> matrixElements;
    int rows;
    int columns;
};

// arifmetic operations
int addToMatrix(Matrix &dst, Matrix &src);
int mulMatrix(Matrix &resMatrix, Matrix &firstMatrix, Matrix &secondMatrix);
void digitMulMatrix(Matrix &dstMatrix, double coef);

// create/delete
void fillMatrix(Matrix &aMatrix, int rows, int columns, double value);
void clearMatrix(Matrix &aMatrix);

// access to values
int setValueMatrix(Matrix &aMatrix, int row, int column);
int getValueMatrix(Matrix &aMatrix, int row, int coumn);


void printMatrix(Matrix  &aMatrix);

#endif // MATRIX_H
