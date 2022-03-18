#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "errors.h"
#include "stdlib.h"
#include "point3d.h"

struct arr
{
   point_3D_t *array;
   int size;
};

typedef struct arr point_arr_t;

int init_point_array(point_arr_t &data, int size);

int free_point_array(point_arr_t &data);


#endif // POINT_ARRAY_H
