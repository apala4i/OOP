#include "actions.h"
#include "controller.h"

int get_figure(figure_t &dst, const figure_t &figure)
{
    return figure_copy(dst, figure);
}

int load_figure(figure_t &figure, char *file_path)
{
    return load_from_file(figure, file_path);
}

int rotate_figure(figure_t &figure, const point_3D_t values)
{
    int rc = SUCCESS;
    matrix_t matrix;
    rc = figure_is_empty(figure) == false ? SUCCESS : EMPTY_FIGURE;
    rc = rc == SUCCESS ? rotate_matrix(matrix, values, figure.figure_center) : rc;
    if (rc == SUCCESS)
    {
        rc = add_transformation(figure, matrix);
        free_matrix(matrix);
    }
    return rc;
}

int translate_figure(figure_t &figure, const point_3D_t values)
{
    int rc = SUCCESS;
    matrix_t matrix;
    rc = figure_is_empty(figure) == false ? SUCCESS : EMPTY_FIGURE;
    rc = rc == SUCCESS ? translate_matrix(matrix, values) : rc;
    if (rc == SUCCESS)
    {
        rc = add_transformation(figure, matrix);
        free_matrix(matrix);
    }
    return rc;
}

int scale_figure(figure_t &figure, const point_3D_t values)
{
    int rc = SUCCESS;
    matrix_t matrix;
    rc = figure_is_empty(figure) == false ? SUCCESS : EMPTY_FIGURE;
    rc = rc == SUCCESS ? scale_matrix(matrix, values, figure.figure_center) : rc;
    if (rc == SUCCESS)
    {
        rc = add_transformation(figure, matrix);
        free_matrix(matrix);
    }
    return rc;
}

int set_center(figure_t &figure, const point_3D_t new_center)
{
    return copy_point_3D(figure.figure_center, new_center);
}
