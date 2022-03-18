#ifndef POINT_3D_H
#define POINT_3D_H

#include "matrix.h"

struct point_3D
{
    double x = 0;
    double y = 0;
    double z = 0;
};

typedef struct point_3D point_3D_t;

point_3D_t make_point_3D(double x, double y, double z);
point_3D_t make_point_3D();
void set_point_3D(point_3D_t &point, double x, double y, double z);
void add_point_3D(point_3D_t &point, double x, double y, double z);
void mul_point_3D(point_3D_t &point, double x, double y, double z);
void mul_point_3D_matrix(point_3D_t &point, const matrix_t &matrix);

#endif // point_3D_t_H
