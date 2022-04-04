#include "actions.h"
#include "controller.h"
#include "error.h"
#include "matrix.h"

int get_figure(model_t &dst, const figure_t &figure)
{
    int points_count;
    int rc = get_points_count(points_count, figure);
    point_2D_t *point_array = NULL;
    if (points_count != 0)
    {
        point_array = (point_2D_t*)malloc(points_count * sizeof(point_2D_t));
        if (point_array == NULL)
            return MALLOC_ERROR;
    }
    for (int i = 0; i < points_count && rc == SUCCESS; i++)
    {
        point_3D_t curr_point;
        rc = get_by_ind_point_array(curr_point, i, figure.points);
        rc = rc == SUCCESS ? point_2D_from_point_3D(point_array[i], curr_point): rc;
    }
    if (rc == SUCCESS)
    {
        dst.point_array = point_array;
        rc = copy_matrix(dst.links, figure.links);
        if (rc == SUCCESS)
        {
            dst.point_counts = points_count;
        }
    }
    return rc;
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
