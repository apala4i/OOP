#ifndef MATRIX_ANOTHER_H
#define MATRIX_ANOTHER_H

#define MATRIX_SIZE_ERROR 1
#define MATRIX_INPUT_ERROR 2

#include "errors.h"

struct matrix
{
    double** matrix_elements;
    int rows;
    int columns;
};

typedef struct matrix matrix_t;

// arifmetic operations
int add_to_matrix(matrix_t &dst, const matrix_t &src);
int mul_matrix(matrix_t &res_matrix, const matrix_t &first_matrix, const matrix_t &second_matrix);
void digit_mul_matrix(matrix_t &dst_matrix, const double coef);

// create/delete
int init_matrix(matrix_t &matrix, const int rows, const int columns);
int free_matrix(matrix_t &matrix);

// access to values
int set_value_matrix(matrix_t &matrix, const int row, const int column);
int get_value_matrix(matrix_t &matrix, const int row, const int coumn);


void print_matrix(const matrix_t &matrix);

#endif // MATRIX_H
