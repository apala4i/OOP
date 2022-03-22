#include "affine_transform.h"

int fill_matrix_rotate_Ox(matrix_t &matrix, const double angle);
int fill_matrix_rotate_Oy(matrix_t &matrix, const double angle);
int fill_matrix_rotate_Oz(matrix_t &matrix, const double angle);

int translate_matrix(matrix_t &matrix, const point_3D_t translate_vector)
{
    matrix_t res_matrix;
    int rc = SUCCESS;
    rc = init_matrix(res_matrix, 4, 4);
    if (rc == 0)
    {
        res_matrix.matrix_elements[0][0] = 1;
        res_matrix.matrix_elements[1][1] = 1;
        res_matrix.matrix_elements[2][2] = 1;
        res_matrix.matrix_elements[3][3] = 1;
        res_matrix.matrix_elements[3][0] = translate_vector.x;
        res_matrix.matrix_elements[3][1] = translate_vector.y;
        res_matrix.matrix_elements[3][2] = translate_vector.z;
        
        matrix.columns = res_matrix.columns;
        matrix.rows = res_matrix.rows;
        matrix.matrix_elements = res_matrix.matrix_elements;
    }
    return rc;
}


int rotate_matrix_O_type(matrix_t &matrix, const double angle, const point_3D_t center, ROTATION_TYPE type)
{
    // make matrix for move to (0;0;0)
    matrix_t move_matrix;
    point_3D_t move;
    int rc = SUCCESS;
    rc = (rc != 0) ? rc : copy_point_3D(move, center);

    rc = (rc != 0) ? rc : minus_point_3D(move);

    rc = (rc != 0) ? rc : translate_matrix(move_matrix, move);


    // make matrix for rotation
    matrix_t rotate_matrix;
    rc = (rc != 0) ? rc : init_matrix(rotate_matrix, 4, 4);

    if (rc == 0)
    {
        switch (type)
        {
        case OX:
            rc = fill_matrix_rotate_Ox(rotate_matrix, angle);
            break;

        case OY:
            rc = fill_matrix_rotate_Oy(rotate_matrix, angle);
            break;

        case OZ:
            rc = fill_matrix_rotate_Oz(rotate_matrix, angle);
            break;

        default:
            rc = BAD_DATA;
        }


        // make matrix for move back to center
        matrix_t back_move_matrix;
        rc = (rc != 0) ? rc : translate_matrix(back_move_matrix, center);

        // multiply matrixes
        matrix_t move_rotate_matrix;
        rc = (rc != 0) ? rc : mul_matrix(move_rotate_matrix, move_matrix, rotate_matrix);
        rc = (rc != 0) ? rc : mul_matrix(matrix, move_rotate_matrix, back_move_matrix);
    }
    return rc;
}

int fill_matrix_rotate_Ox(matrix_t &matrix, const double angle)
{
    int rc = SUCCESS;

    if (matrix.columns != 4 || matrix.rows != 4)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        matrix.matrix_elements[1][1] = cos(angle * PI / 180);
        matrix.matrix_elements[1][2] = sin(angle * PI / 180);
        matrix.matrix_elements[2][1] = -sin(angle * PI / 180);
        matrix.matrix_elements[2][2] = cos(angle * PI / 180);
        matrix.matrix_elements[0][0] = 1;
        matrix.matrix_elements[3][3] = 1;
    }
    return rc;
}

int fill_matrix_rotate_Oy(matrix_t &matrix, const double angle)
{
    int rc = SUCCESS;

    if (matrix.columns != 4 || matrix.rows != 4)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        matrix.matrix_elements[0][0] = cos(angle * PI /180);
        matrix.matrix_elements[0][2] = -sin(angle * PI / 180);
        matrix.matrix_elements[2][0] = sin(angle * PI / 180);
        matrix.matrix_elements[2][2] = cos(angle * PI / 180);
        matrix.matrix_elements[1][1] = 1;
        matrix.matrix_elements[3][3] = 1;
    }
    return rc;
}

int fill_matrix_rotate_Oz(matrix_t &matrix, const double angle)
{
    int rc = SUCCESS;

    if (matrix.columns != 4 || matrix.rows != 4)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        matrix.matrix_elements[0][0] = cos(angle * PI / 180);
        matrix.matrix_elements[0][1] = sin(angle * PI / 180);
        matrix.matrix_elements[1][0] = -sin(angle * PI / 180);
        matrix.matrix_elements[1][1] = cos(angle * PI / 180);
        matrix.matrix_elements[2][2] = 1;
        matrix.matrix_elements[3][3] = 1;
    }
    return rc;
}

int rotate_matrix_Oz(matrix_t &matrix, const double angle, const point_3D_t center)
{
    // make matrix for move to (0;0;0)
    matrix_t move_matrix;
    point_3D_t move;
    int rc = SUCCESS;
    rc = (rc != 0) ? rc : copy_point_3D(move, center);

    rc = (rc != 0) ? rc : minus_point_3D(move);

    rc = (rc != 0) ? rc : translate_matrix(move_matrix, move);


    // make matrix for rotation
    matrix_t rotate_matrix;
    rc = (rc != 0) ? rc : init_matrix(rotate_matrix, 4, 4);

    if (rc == 0)
    {
        rotate_matrix.matrix_elements[0][0] = cos(angle * PI / 180);
        rotate_matrix.matrix_elements[0][1] = sin(angle * PI / 180);
        rotate_matrix.matrix_elements[1][0] = -sin(angle * PI / 180);
        rotate_matrix.matrix_elements[1][1] = cos(angle * PI / 180);
        rotate_matrix.matrix_elements[2][2] = 1;
        rotate_matrix.matrix_elements[3][3] = 1;

        // make matrix for move back to center
        matrix_t back_move_matrix;
        rc = (rc != 0) ? rc : translate_matrix(back_move_matrix, center);

        // multiply matrixes
        matrix_t move_rotate_matrix;
        rc = (rc != 0) ? rc : mul_matrix(move_rotate_matrix, move_matrix, rotate_matrix);
        rc = (rc != 0) ? rc : mul_matrix(matrix, move_rotate_matrix, back_move_matrix);
    }   
    return rc;
}

int scale_matrix(matrix_t &matrix, const point_3D_t scale_coefficient, const point_3D_t center)
{
    // make matrix for move to (0;0;0)
    matrix_t move_matrix;
    point_3D_t move;
    int rc = SUCCESS;
    rc = (rc != 0) ? rc : copy_point_3D(move, center);

    rc = (rc != 0) ? rc : minus_point_3D(move);

    rc = (rc != 0) ? rc : translate_matrix(move_matrix, move);

    // make matrix for scale
    matrix_t scale_matrix;
    rc = (rc != 0) ? rc : init_matrix(scale_matrix, 4, 4);

    if (rc == 0)
    {
        scale_matrix.matrix_elements[0][0] = scale_coefficient.x;
        scale_matrix.matrix_elements[1][1] = scale_coefficient.y;
        scale_matrix.matrix_elements[2][2] = scale_coefficient.z;
        scale_matrix.matrix_elements[3][3] = 1;

        // make matrix for move back to center
        matrix_t back_move_matrix;
        rc = (rc != 0) ? rc : translate_matrix(back_move_matrix, center);

        // multiply matrixes
        matrix_t move_scale_matrix;
        rc = (rc != 0) ? rc : mul_matrix(move_scale_matrix, move_matrix, scale_matrix);
        rc = (rc != 0) ? rc : mul_matrix(matrix, move_scale_matrix, back_move_matrix);
    }
    return rc;
}

int rotate_matrix(matrix_t &matrix, const point_3D_t rotate_angles, const point_3D_t center)
{
    int rc = SUCCESS;
    matrix_t matrix_Ox;
    matrix_t matrix_Oy;
    matrix_t matrix_Oz;

    rc = rc != 0 ? rc : rotate_matrix_O_type(matrix_Ox, rotate_angles.x, center, OX);
    rc = rc != 0 ? rc : rotate_matrix_O_type(matrix_Oy, rotate_angles.y, center, OY);
    rc = rc != 0 ? rc : rotate_matrix_O_type(matrix_Oz, rotate_angles.z, center, OZ);

    matrix_t tmp;
    rc = rc != 0 ? rc : mul_matrix(tmp, matrix_Ox, matrix_Oy);
    rc = rc != 0 ? rc : mul_matrix(matrix, tmp, matrix_Oz);
    return rc;
}
