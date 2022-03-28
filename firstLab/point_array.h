#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "errors.h"
#include "stdlib.h"
#include "point3d.h"
#include <cstdio>

#define START_SIZE 10

struct arr
{
   struct point_3D *array = NULL;
   int capacity = 0;
   int size = 0;
};

typedef struct arr point_arr_t;

int init_point_array(point_arr_t &data, int size);

int free_point_array(point_arr_t &data);

int resize_point_array(point_arr_t &data, const int new_capacity);

int push_back_point(point_arr_t &data, const point_3D_t &point);

int push_back_point_by_cord(point_arr_t &data, double x, double y, double z);

int print_point_array(FILE *file, const point_arr_t &point_arr);

int get_size_point_array(const point_arr_t &point_arr);

int copy_point_array(point_arr_t &dst, const point_arr_t &src);

int get_by_ind_point_array(point_3D_t &value, const int ind, const point_arr_t &point_arr);

bool point_array_empty(const point_arr_t &point_arr);

int mul_point_on_matrix_by_ind(point_arr_t &point_arr, const int index, const matrix_t &matrix);

#endif // POINT_ARRAY_H
