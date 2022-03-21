#ifndef AFFINETRANSFORMATIOS_H
#define AFFINETRANSFORMATIOS_H

#include "matrix.h"
#include "point3d.h"
#include <cmath>

#define PI 3.1415

int translate_matrix(matrix_t &matrix, const point_3D_t translate_vector);
int rotate_matrix_Ox(matrix_t &matrix, const double angle, const point_3D_t center);
int rotate_matrix_Oy(matrix_t &matrix, const double angle, const point_3D_t center);
int rotate_matrix_Oz(matrix_t &matrix, const double angle, const point_3D_t center);
int scale_matrix(matrix_t &matrix, const point_3D_t scale_coefficient, const point_3D_t center);
int rotate_matrix(matrix_t &matrix, const point_3D_t rotate_angles, const point_3D_t center);

#endif // AFFINETRANSFORMATIOS_H
