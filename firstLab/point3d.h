#ifndef POINT3D_H
#define POINT3D_H

#include "matrix.h"

typedef struct Point3D Point3D;
struct Point3D
{
    double x = 0;
    double y = 0;
    double z = 0;
};

Point3D makePoint3D(double x, double y, double z);
Point3D makePoint3D();
void setPoint3D(Point3D &aPoint, double x, double y, double z);
void addPoint3D(Point3D &aPoint, double x, double y, double z);
void mulPoint3D(Point3D &aPoint, double x, double y, double z);
void mulPoint3DMatrix(Point3D &aPoint, Matrix aMatrix);

#endif // POINT3D_H
