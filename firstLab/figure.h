#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include "point3d.h"
#include "matrix.h"
#include "point_array.h"


struct figure
{
    point_arr_t Points;
    point_3D_t figureCenter;
};
typedef struct figure figure_t;

int add_transformation(figure_t &figure, matrix_t const &transformation);


#endif // FIGURE_H
