#include "controller.h"

static figure_t figure;


int make_action(const ACTIONS action, const point_3D_t value)
{
    int rc = SUCCESS;
    switch (action)
    {
        case ROTATE:
            rc = rotate_figure(value);
            break;
        case TRANSLATE:
            rc =  translate_figure(value);
            break;
        case SCALE:
            rc = scale_figure(value);
            break;
        case SET_CENTER:
            rc = set_center(value);
            break;
        case GET_FIGURE:
            rc = init_figure();
            break;
        case UNKNOWN:
            break;
    }
    return rc;
}

int make_action(const ACTIONS action, figure_t &dst)
{
    int rc = SUCCESS;

    rc = action == GET_FIGURE ? figure_copy(dst, figure) : WRONG_COMMAND;

    return rc;
}

int make_action(const ACTIONS action)
{
    int rc = SUCCESS;
    rc = action == LOAD_FIGURE ? load_from_file(figure, FILE_PATH) : WRONG_COMMAND;
    return rc;
}

int rotate_figure(const point_3D_t values)
{
    int rc = SUCCESS;
    matrix_t matrix;
    rc = figure_is_empty(figure) == false ? SUCCESS : EMPTY_FIGURE;
    rc = rc == SUCCESS ? rotate_matrix(matrix, values, figure.figure_center) : rc;
    rc = rc == SUCCESS ? add_transformation(figure, matrix) : rc;
    rc = rc == SUCCESS ? free_matrix(matrix) : rc;
    return rc;
}

int translate_figure(const point_3D_t values)
{
    int rc = SUCCESS;
    matrix_t matrix;
    rc = figure_is_empty(figure) == false ? SUCCESS : EMPTY_FIGURE;
    rc = rc == SUCCESS ? translate_matrix(matrix, values) : rc;
    rc = rc == SUCCESS ? add_transformation(figure, matrix) : rc;
    rc = rc == SUCCESS ? free_matrix(matrix) : rc;
    return rc;
}

int scale_figure(const point_3D_t values)
{
    int rc = SUCCESS;
    matrix_t matrix;
    rc = figure_is_empty(figure) == false ? SUCCESS : EMPTY_FIGURE;
    rc = rc == SUCCESS ? scale_matrix(matrix, values, figure.figure_center) : rc;
    rc = rc == SUCCESS ? add_transformation(figure, matrix) : rc;
    rc = rc == SUCCESS ? free_matrix(matrix) : rc;
    return rc;
}


int set_center(const point_3D_t new_center)
{
    return copy_point_3D(figure.figure_center, new_center);
}

int init_figure()
{
    return load_from_file(figure, FILE_PATH);
}
