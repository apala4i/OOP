#include "point_array.h"
#include <cstring>

int init_point_array(point_arr_t &data, int capacity = START_SIZE)
{
    int rc = SUCCESS;
    if ( capacity < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        point_3D_t *tmp = (point_3D_t *)malloc(sizeof (point_3D_t) * capacity);
        if (tmp == NULL)
        {
            rc = MALLOC_ERROR;
        }
        else
        {
            data.array = tmp;
            data.capacity = capacity;
            data.size = 0;
        }
    }
    return rc;
}


int free_point_array(point_arr_t &data)
{
    int rc = SUCCESS;
    if (data.capacity < 0)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        free(data.array);
        data.array = NULL;
        data.size = 0;
        data.capacity = 0;
    }
    return rc;
}

int push_back_point_by_cord(point_arr_t &data, double x, double y, double z)
{
    int rc = SUCCESS;
    point_3D_t adding_point;
    set_point_3D(adding_point, x, y, z);
    rc = push_back_point(data, adding_point);
    return rc;
}

int push_back_point(point_arr_t &data, const point_3D_t &point)
{
    int rc = SUCCESS;

    if (data.capacity < 0 || data.size < 0)
    {
        rc = BAD_DATA;
    }
    else
    {
        if (data.size == data.capacity)
        {
            rc = resize_point_array(data, (data.capacity == 0) ? START_SIZE : data.capacity * 2);
        }
    }
    if (rc == SUCCESS)
    {
        set_point_3D(data.array[data.size++], point.x, point.y, point.z);
    }

    return rc;
}

int resize_point_array(point_arr_t &data, const int new_capacity)
{
    int rc = SUCCESS;
    if (data.capacity < 0 || data.size < 0 || new_capacity < 1)
    {
        rc = BAD_ARG_ERROR;
    }
    else
    {
        point_3D_t *tmp;
        if (data.size == 0)
        {
            tmp = (point_3D_t *)malloc(new_capacity * sizeof(point_3D_t));
        }
        else
        {
            tmp = (point_3D_t *)realloc(data.array, new_capacity * sizeof(point_3D_t));
        }

        if (tmp == NULL)
        {
            rc = MALLOC_ERROR;
        }
        else
        {
            data.array = tmp;
            data.capacity = new_capacity;
        }
    }
    return rc;
}

int print_point_array(FILE *file, const point_arr_t &data)
{
    int rc = SUCCESS;
    if (data.size == 0)
    {
        rc = EMPTY_DATA_ERROR;
    }
    else
    {
        for (int i = 0; i < data.size; ++i)
        {
            print_point(file, data.array[i]);
        }
    }
    return rc;
}

bool point_array_empty(const point_arr_t &point_arr)
{
    return point_arr.size == 0;
}

int get_size_point_array(const point_arr_t &point_arr)
{
    return point_arr.size;
}

int get_by_ind_point_array(point_3D_t &value, const int ind, const point_arr_t &point_arr)
{
    int rc = SUCCESS;
    rc = ind < 0 ? BAD_ARG_ERROR : SUCCESS;
    rc = rc == SUCCESS && ind >= point_arr.size ? INDEX_OUT_OF_RANGE : SUCCESS;
    value = rc == SUCCESS ? point_arr.array[ind] : value;
    return rc;
}

int copy_point_array(point_arr_t &dst, const point_arr_t &src)
{
    int rc = SUCCESS;
    point_3D_t *tmp = (point_3D_t *)calloc(src.capacity, sizeof(point_3D_t));
    if (tmp == NULL)
    {
        rc = MALLOC_ERROR;
    }
    else
    {
        free_point_array(dst);

        memcpy(tmp, src.array, sizeof(point_3D_t) * src.size);
        dst.array = tmp;
        dst.capacity = src.capacity;
        dst.size = src.size;
    }
    return rc;
}

int mul_point_on_matrix_by_ind(point_arr_t &point_arr, const int index, const matrix_t &matrix)
{
    return mul_point_3D_matrix(point_arr.array[index], matrix);
}
