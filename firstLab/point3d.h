#ifndef POINT_3D_H
#define POINT_3D_H

#include "matrix.h"
#include <cstdio>

struct point_3D
{
    double x = 0;
    double y = 0;
    double z = 0;
};

typedef struct point_3D point_3D_t;

int set_point_3D(point_3D_t &point, const double x, const double y, const double z);
int add_point_3D(point_3D_t &point, const double x, const double y, const double z);
int mul_point_3D(point_3D_t &point, const double x, const double y, const double z);
int mul_point_3D_matrix(point_3D_t &point, const matrix_t &matrix);
int minus_point_3D(point_3D_t &point);
int copy_point_3D(point_3D_t &dst, const point_3D_t &src);
int matrix_from_point_3D(matrix_t &matrix, const point_3D_t point);

int print_point(FILE *file, const point_3D_t &dst);
#endif // point_3D_H
