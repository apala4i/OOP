#include "figure.h"
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
        for (int i = 0;i < figure.Points.size; ++i)
        {
            mul_point_3D_matrix(figure.Points.array[i], transformation);
        }
    }

    return rc;
}

int get_points_count(int &count, const figure_t &figure)
{
    count = figure.Points.size;
    return SUCCESS;
}

int add_point_to_figure(figure_t &figure, const point_3D_t point)
{
    return push_back_point(figure.Points, point);
}

int add_point_to_figure(figure_t &figure, const double x, const double y, const double z)
{
    return push_back_point_by_cord(figure.Points, x, y, z);
}

int init_links_matrix(figure_t &figure)
{
    int rc = SUCCESS;
    if (figure.Points.size < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        matrix_t tmp_matrix;
        rc = init_matrix(tmp_matrix, figure.Points.size, figure.Points.size);
        if (rc == SUCCESS)
        {
            figure.links.columns = tmp_matrix.columns;
            figure.links.matrix_elements = tmp_matrix.matrix_elements;
            figure.links.rows = tmp_matrix.rows;
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
        if (figure.links.columns != 0)
        {
            free(figure.links.matrix_elements);
        }
        figure.links.columns = tmp_matrix.columns;
        figure.links.matrix_elements = tmp_matrix.matrix_elements;
        figure.links.rows = tmp_matrix.rows;
    }
    return rc;
}

int add_link_to_figure(figure_t &figure, const int from, const int to)
{
    int rc = SUCCESS;
    int columns = figure.links.columns;
    int rows = figure.links.rows;
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
    copy_point_3D(dst.figureCenter,  src.figureCenter);
    
    if (dst.links.columns != 0)
    {
        free(dst.links.matrix_elements);
    }
    dst.links.columns = src.links.columns;
    dst.links.matrix_elements = src.links.matrix_elements;
    dst.links.rows = src.links.rows;
    
    if (dst.Points.size != 0)
    {
        free(dst.Points.array);
    }
    dst.Points.array = src.Points.array;
    dst.Points.capacity = src.Points.capacity;
    dst.Points.size = src.Points.size;

    return SUCCESS;
    
}

int print_figure(FILE *file, const figure_t figure)
{
    print_point_array(file, figure.Points);
    print_matrix(file, figure.links);
    return SUCCESS;
}
