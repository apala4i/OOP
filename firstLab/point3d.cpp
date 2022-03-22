#include "point3d.h"
#include <stdlib.h>
#include <cstdio>

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
    int rc = SUCCESS;
    matrix_t point_matrix;
    rc = matrix_from_point_3D(point_matrix, point);
    if (rc == SUCCESS)
    {
        matrix_t res_matrix;
        rc = mul_matrix(res_matrix, point_matrix, matrix);
        if (rc == SUCCESS)
        {
            point.x = res_matrix.matrix_elements[0][0];
            point.y = res_matrix.matrix_elements[0][1];
            point.z = res_matrix.matrix_elements[0][2];
        }
        free_matrix(res_matrix);
        free_matrix(point_matrix);
    }
    return rc;
}

int matrix_from_point_3D(matrix_t &matrix, const point_3D_t point)
{
    int rc = SUCCESS;
    free_matrix(matrix);
    rc = init_matrix(matrix, 1,  4);
    if (rc == SUCCESS)
    {
        matrix.matrix_elements[0][0] = point.x;
        matrix.matrix_elements[0][1] = point.y;
        matrix.matrix_elements[0][2] = point.z;
        matrix.matrix_elements[0][3] = 1.;
    }
    return rc;
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
    int rc = SUCCESS;
    if (file != NULL)
    {
        fprintf(file, "%lf %lf %lf\n", point.x, point.y, point.z);
    }
    else
    {
        rc = FILE_ERROR;
    }
    return rc;
}
