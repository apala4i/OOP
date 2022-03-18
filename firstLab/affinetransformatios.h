#ifndef AFFINETRANSFORMATIOS_H
#define AFFINETRANSFORMATIOS_H

#include "matrix.h"
#include "point3d.h"

int rotate_matrix(matrix_t &matrix, const double angle, const point_3D_t center);
int scale_matrix(matrix_t &matrix, const double coef);
int translate_matrix(matrix_t &matrix, const point_3D_t translate_vector);

#endif // AFFINETRANSFORMATIOS_H
