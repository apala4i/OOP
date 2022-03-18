#include "matrix.h"
#include <iostream>
//typedef struct Matrix Matrix;
//struct Matrix
//{
//    std::vector<double> matrixElements;
//};

// arifmetic operations
int addToMatrix(Matrix &dst, Matrix &src)
{
    int rc = EXIT_SUCCESS;
    if (dst.columns != src.columns ||
        dst.rows != src.rows)
    {
        return MATRIX_SIZE_ERROR;
    }
    else
    {
        for (int i = 0; i < dst.rows; ++i)
        {
            for(int j = 0; j < dst.columns; ++j)
            {
                dst.matrixElements[i][j] += src.matrixElements[i][j];
            }
        }
    }
    return rc;
}

int mulMatrix(Matrix &resMatrix, Matrix &firstMatrix, Matrix &secondMatrix)
{
    int rc = EXIT_SUCCESS;
    if (firstMatrix.columns != secondMatrix.rows)
    {
        return MATRIX_SIZE_ERROR;
    }
    else
    {
        fillMatrix(resMatrix, firstMatrix.rows, secondMatrix.columns, 0.);
        for (int i = 0; i < resMatrix.rows; ++i)
        {
            for (int j = 0; j < resMatrix.columns; ++j)
            {
                resMatrix.matrixElements[i][j] = 0.;
                for (int k = 0; k < firstMatrix.columns; ++k)
                {
                    resMatrix.matrixElements[i][j] += firstMatrix.matrixElements[i][k] * secondMatrix.matrixElements[k][j];
                }
            }
        }
    }
    return rc;
}

void digitMulMatrix(Matrix &dstMatrix, double coef)
{
    for (int i = 0; i < dstMatrix.rows; ++i)
    {
        for (int j = 0; j < dstMatrix.columns; ++j)
        {
            dstMatrix.matrixElements[i][j] *= coef;
        }
    }
}

// create/delete
void fillMatrix(Matrix &aMatrix, int rows, int columns, double value)
{
    aMatrix.rows = rows;
    aMatrix.columns = columns;
    aMatrix.matrixElements.resize(rows);

    for (int i = 0; i < rows; ++i)
    {
        aMatrix.matrixElements[i].resize(columns, value);
    }

    for (std::vector<double> &x: aMatrix.matrixElements)
    {
        x.resize(columns, 0.);
    }
}


void clearMatrix(Matrix &aMatrix)
{
    aMatrix.matrixElements.clear();
}

// access to values
int setValueMatrix(Matrix &aMatrix, int row, int column);
int getValueMatrix(Matrix &aMatrix, int row, int coumn);


void printMatrix(Matrix  &aMatrix)
{
    for (int i = 0; i < aMatrix.rows; ++i)
    {
        for (int j = 0; j < aMatrix.columns; ++j)
        {
            std::cout << aMatrix.matrixElements[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
