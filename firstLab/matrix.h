#ifndef MATRIX_ANOTHER_H
#define MATRIX_ANOTHER_H

#define MATRIX_SIZE_ERROR 1
#define MATRIX_INPUT_ERROR 2

#include "errors.h"
#include <cstdio>

struct matrix
{
    double** matrix_elements = NULL;
    int rows = 0;
    int columns = 0;
};

typedef struct matrix matrix_t;

// arifmetic operations
int add_to_matrix(matrix_t &dst, const matrix_t &src);
int mul_matrix(matrix_t &res_matrix, const matrix_t &first_matrix, const matrix_t &second_matrix);
void digit_mul_matrix(matrix_t &dst_matrix, const double coef);

// create/delete
int init_matrix(matrix_t &matrix, const int rows, const int columns);
int free_matrix(matrix_t &matrix);

int print_matrix(FILE *file, const matrix_t &matrix);

int copy_matrix(matrix_t &dst, const matrix_t &src);

int copy_matrix_elements(matrix &dst,  const matrix_t &src);

#endif // MATRIX_H
