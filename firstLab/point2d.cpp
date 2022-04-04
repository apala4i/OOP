#include "point2d.h"

int point_2D_from_point_3D(point_2D_t &dst, const point_3D_t src)
{
    dst.x = src.x;
    dst.y = src.y;
    return 0;;
}
