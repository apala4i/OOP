#ifndef AFFINETRANSFORMATIOS_H
#define AFFINETRANSFORMATIOS_H

#include "matrix.h"
#include "point3d.h"

Matrix rotateMatrix(double angle, Point3D center);
Matrix scaleMatrix(double coef);
Matrix translateMatrix(Point3D translateVector);

#endif // AFFINETRANSFORMATIOS_H
