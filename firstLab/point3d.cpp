#include "point3d.h"


point_3D_t makePoint3D(double x, double y, double z);
point_3D_t makePoint3D();

void set_point_3D(point_3D_t &point, double x, double y, double z)
{
    point.x = x;
    point.y = y;
    point.z = z;
}

void add_point_3D(point_3D_t &point, double x, double y, double z)
{
    point.x += x;
    point.y += y;
    point.z += z;
}

void mul_point_3D(point_3D_t &point, double x, double y, double z)
{
    point.x *= x;
    point.y *= y;
    point.z *= z;
}

void mul_point_3D_matrix(point_3D_t &point, const matrix_t &matrix)
{
    matrix_t pointMatrix;
    init_matrix(pointMatrix, 1, 3);
    pointMatrix.matrix_elements[0][0] = point.x;
    pointMatrix.matrix_elements[1][0] = point.y;
    pointMatrix.matrix_elements[2][0] = point.z;

    matrix_t resMatrix;
    mul_matrix(resMatrix, pointMatrix, matrix);
    point.x = resMatrix.matrix_elements[0][0];
    point.x = resMatrix.matrix_elements[1][0];
    point.x = resMatrix.matrix_elements[2][0];
}
