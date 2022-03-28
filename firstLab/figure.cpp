#include "figure.h"
#include "matrix.h"
#include "point_array.h"
#include "point_array.h"

int add_transformation(figure_t &figure, const matrix_t &transformation)
{
    int rc = SUCCESS;

    if (transformation.rows != 4)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        figure_t tmp;
        rc = figure_copy(tmp, figure);
        for (int i = 0;rc == SUCCESS && i < get_size_point_array(tmp.points); ++i)
        {
            rc = rc == SUCCESS ? mul_point_on_matrix_by_ind(tmp.points, i, transformation) : rc;
        }
        if (rc == SUCCESS)
        {
            rc = figure_copy(figure, tmp);
            free_figure(tmp);
        }
    }

    return rc;
}

int get_points_count(int &count, const figure_t &figure)
{
    count = get_size_point_array(figure.points);
    return SUCCESS;
}

int add_point_to_figure(figure_t &figure, const point_3D_t point)
{
    return push_back_point(figure.points, point);
}

int add_point_to_figure(figure_t &figure, const double x, const double y, const double z)
{
    return push_back_point_by_cord(figure.points, x, y, z);
}

int init_links_matrix(figure_t &figure)
{
    int rc = SUCCESS;
    int size = get_size_point_array(figure.points);
    if (size < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        matrix_t tmp_matrix;
        rc = init_matrix(tmp_matrix, size, size);
        if (rc == SUCCESS)
        {
            set_matrix(figure.links, tmp_matrix);
        }
        else
        {
            free_matrix(figure.links);
        }
    }
    return rc;
}

int init_links_matrix(figure_t &figure, const int &size)
{
    int rc = SUCCESS;
    matrix_t tmp_matrix;
    rc = init_matrix(tmp_matrix, size, size);
    if (rc == SUCCESS)
    {
        if (get_columns_matrix(figure.links) != 0)
        {
            free_matrix(figure.links);
        }
        set_matrix(figure.links, tmp_matrix);
    }
    return rc;
}

int add_link_to_figure(figure_t &figure, const int from, const int to)
{
    int rc = SUCCESS;
    int columns = get_columns_matrix(figure.links);
    int rows = get_rows_matrix(figure.links);

    rc = (rc == 0 && columns != rows) ? SIZE_ERROR : SUCCESS;
    rc = (rc == 0 && rows == 0) ? EMPTY_DATA_ERROR : SUCCESS;
    rc = (rc == 0 && rows < 0) ? BAD_DATA : SUCCESS;
    rc = (rc == 0 && (from >= rows || to >= rows)) ? INDEX_OUT_OF_RANGE : SUCCESS;
    
    if (rc == SUCCESS)
    {
        figure.links.matrix_elements[from][to] = 1;
        figure.links.matrix_elements[to][from] = 1;
    }

    return rc;
}

int figure_copy(figure_t &dst, const figure_t &src)
{
    int rc = SUCCESS;

    rc = copy_point_3D(dst.figure_center,  src.figure_center);
    
    rc = rc == SUCCESS ? copy_point_array(dst.points, src.points) : rc;

    rc = rc == SUCCESS ? copy_matrix(dst.links, src.links) : rc;

    return rc;
}

int print_figure(FILE *file, const figure_t figure)
{
    print_point_array(file, figure.points);
    print_matrix(file, figure.links);
    return SUCCESS;
}

int free_figure(figure_t &figure)
{
    int rc = SUCCESS;
    rc = free_matrix(figure.links);
    rc = rc != SUCCESS ? rc: free_point_array(figure.points);
    return rc;
}

bool figure_is_empty(figure_t figure)
{
    return point_array_empty(figure.points);
}
