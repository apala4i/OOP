#ifndef AFFINETRANSFORMATIOS_H
#define AFFINETRANSFORMATIOS_H

#include "matrix.h"
#include "point3d.h"
#include <cmath>

#define PI 3.1415

typedef enum
{
    OX,
    OY,
    OZ
}ROTATION_TYPE;

int move_matrix(matrix_t &matrix, const point_3D_t translate_vector);
int scale_matrix(matrix_t &matrix, const point_3D_t scale_coefficient, const point_3D_t center);
int rotate_matrix(matrix_t &matrix, const point_3D_t rotate_angles, const point_3D_t center);

#endif // AFFINETRANSFORMATIOS_H
