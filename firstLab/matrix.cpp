#include "matrix.h"
#include <iostream>


// arifmetic operations
int add_to_matrix(matrix_t &dst, const matrix_t &src)
{
    int rc = EXIT_SUCCESS;
    if (dst.columns != src.columns ||
        dst.rows != src.rows)
    {
        return SIZE_ERROR;
    }
    else
    {
        for (int i = 0; i < dst.rows; ++i)
        {
            for(int j = 0; j < dst.columns; ++j)
            {
                dst.matrix_elements[i][j] += src.matrix_elements[i][j];
            }
        }
    }
    return rc;
}

int mul_matrix(matrix_t &res_matrix, const matrix_t &first_matrix, const matrix_t &second_matrix)
{
    int rc = EXIT_SUCCESS;
    if (first_matrix.columns != second_matrix.rows)
    {
        return SIZE_ERROR;
    }
    else
    {
        init_matrix(res_matrix, first_matrix.rows, second_matrix.columns);
        for (int i = 0; i < res_matrix.rows; ++i)
        {
            for (int j = 0; j < res_matrix.columns; ++j)
            {
                res_matrix.matrix_elements[i][j] = 0.;
                for (int k = 0; k < first_matrix.columns; ++k)
                {
                    res_matrix.matrix_elements[i][j] += first_matrix.matrix_elements[i][k] * second_matrix.matrix_elements[k][j];
                }
            }
        }
    }
    return rc;
}

void digit_mul_matrix(matrix_t &dstmatrix_t, const double coef)
{
    for (int i = 0; i < dstmatrix_t.rows; ++i)
    {
        for (int j = 0; j < dstmatrix_t.columns; ++j)
        {
            dstmatrix_t.matrix_elements[i][j] *= coef;
        }
    }
}

// create/delete
int init_matrix(matrix_t &matrix_t, const int rows, const int columns)
{
    int rc = EXIT_SUCCESS;
    if (rows < 1 || columns < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        matrix_t.matrix_elements = (double **)calloc(rows, sizeof(double *));
        if (matrix_t.matrix_elements == NULL)
        {
            rc = MALLOC_ERROR;
        }
        else
        {
            matrix_t.columns = columns;
            matrix_t.rows = rows;
            for (int i = 0; i < rows && rc == EXIT_SUCCESS; ++i)
            {
                matrix_t.matrix_elements[i] = (double *)malloc(sizeof(double) * columns);
                if (matrix_t.matrix_elements[i] == NULL)
                {
                    free_matrix(matrix_t);
                    rc = MALLOC_ERROR;
                }
            }
            
        }
    }
    return rc;
}

int free_matrix(matrix_t &matrix)
{
    int rc = EXIT_SUCCESS;
    if (matrix.columns < 1 || matrix.rows < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        for (int i = 0; i < matrix.columns; i++)
        {
            free(matrix.matrix_elements[i]);
        }
        free(matrix.matrix_elements);
        matrix.rows = 0;
        matrix.columns = 0;
    }
    return rc;
}

// access to values
int set_value_matrix(matrix_t &matrix_t, const int row, const int column);
int get_value_matrix(matrix_t &matrix_t, const int row, const int coumn);


void print_matrix(const matrix_t  &matrix_t)
{
    for (int i = 0; i < matrix_t.rows; ++i)
    {
        for (int j = 0; j < matrix_t.columns; ++j)
        {
            std::cout << matrix_t.matrix_elements[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
