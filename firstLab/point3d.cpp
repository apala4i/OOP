#include "point3d.h"
#include <stdlib.h>
#include <cstdio>

int make_point_3D(point_3D_t *point, const double x, const double y, const double z)
{
    int rc = SUCCESS;
    point_3D_t *tmp_point = (point_3D_t *)malloc(sizeof(point_3D_t));
    if (tmp_point == NULL)
    {
        rc = MALLOC_ERROR;
    }
    else
    {
        rc = set_point_3D(*tmp_point, x, y, z);
    }
    return rc;
}

int set_point_3D(point_3D_t &point, const double x, const double y, const double z)
{
    point.x = x;
    point.y = y;
    point.z = z;
    return SUCCESS;
}

int add_point_3D(point_3D_t &point, const double x, const double y, const double z)
{
    point.x += x;
    point.y += y;
    point.z += z;
    return SUCCESS;
}

int mul_point_3D(point_3D_t &point, const double x, const double y, const double z)
{
    point.x *= x;
    point.y *= y;
    point.z *= z;
    return SUCCESS;
}

int mul_point_3D_matrix(point_3D_t &point, const matrix_t &matrix)
{
    matrix_t pointMatrix;
    init_matrix(pointMatrix, 1, 3);
    pointMatrix.matrix_elements[0][0] = point.x;
    pointMatrix.matrix_elements[1][0] = point.y;
    pointMatrix.matrix_elements[2][0] = point.z;

    matrix_t resMatrix;
    mul_matrix(resMatrix, pointMatrix, matrix);
    point.x = resMatrix.matrix_elements[0][0];
    point.y = resMatrix.matrix_elements[1][0];
    point.z = resMatrix.matrix_elements[2][0];
    return SUCCESS;
}


int minus_point_3D(point_3D_t &point)
{
    point.x *= -1;
    point.y *= -1;
    point.z *= -1;
    return SUCCESS;
}

int copy_point_3D(point_3D_t &dst, const point_3D_t &src)
{
    dst.x = src.x;
    dst.y = src.y;
    dst.z = src.z;
    return SUCCESS;
}

int print_point(FILE *file, const point_3D_t &point)
{
    fprintf(file, "%lf %lf %lf\n", point.x, point.y, point.z);
    return SUCCESS;
}
