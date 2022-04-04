#ifndef POINT2D_H
#define POINT2D_H

#include "point3d.h"

typedef struct point_2D
{
    double x;
    double y;
} point_2D_t;

int point_2D_from_point_3D(point_2D_t &dst, const point_3D_t src);

#endif // POINT2D_H
