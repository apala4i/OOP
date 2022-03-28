#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include "point3d.h"
#include "matrix.h"
#include "point_array.h"


struct figure
{
    point_arr_t points;
    point_3D_t figure_center;
    matrix_t links;
};
typedef struct figure figure_t;

int add_transformation(figure_t &figure, const matrix_t &transformation);

int add_point_to_figure(figure_t &figure, const point_3D_t point);

int add_point_to_figure(figure_t &figure, const double x, const double y, const double z);

int get_points_count(int &count, const figure_t &figure);

int init_links_matrix(figure_t &figure);

int init_links_matrix(figure_t &figure, const int &size);

int add_link_to_figure(figure_t &figure, const int from, const int to);

int add_transformation(figure_t &figure, const matrix_t &transformation);

int figure_copy(figure_t &dst, const figure_t &src);

int free_figure(figure_t &figure);

int print_figure(FILE *file, const figure_t figure);

bool figure_is_empty(figure_t fugure);



#endif // FIGURE_H
