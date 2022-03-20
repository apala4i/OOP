#include "point_array.h"

int init_point_array(point_arr_t &data, int capacity = START_SIZE)
{
    int rc = SUCCESS;
    if ( capacity < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        data.array = (point_3D_t *)malloc(sizeof (point_3D_t) * capacity);
        if (data.array == NULL)
        {
            rc = MALLOC_ERROR;
        }
        else
        {
            data.capacity = capacity;
            data.size = 0;
        }
    }
    return rc;
}


int free_point_array(point_arr_t &data)
{
    int rc = SUCCESS;
    if (data.capacity < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        free(data.array);
        data.size = 0;
        data.capacity = 0;
    }
    return rc;
}

int push_back_point_by_cord(point_arr_t &data, double x, double y, double z)
{
    int rc = SUCCESS;
    point_3D_t *adding_point = (point_3D_t *)malloc(sizeof(point_3D_t));
    if (adding_point == NULL)
    {
        rc = MALLOC_ERROR;
    }
    else
    {
        set_point_3D(*adding_point, x, y, z);
        rc = push_back_point(data, *adding_point);
    }
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
        data.array[data.size++] = point;
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
