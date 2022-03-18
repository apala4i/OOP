#include "point_array.h"

int init_point_array(point_arr_t &data, int size)
{
    int rc = SUCCESS;
    if ( size < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        data.array = (point_3D_t *)malloc(sizeof (point_3D_t) * size);
        if (data.array == NULL)
        {
            rc = MALLOC_ERROR;
        }
        else
        {
            data.size = size;
        }
    }
    return rc;
}

int free_point_array(point_arr_t &data)
{
    int rc = EXIT_SUCCESS;
    if (data.size < 1)
    {
        rc = SIZE_ERROR;
    }
    else
    {
        free(data.array);
        data.size = 0;
    }
    return rc;
}