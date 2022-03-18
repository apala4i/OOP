#include "point3d.h"


Point3D makePoint3D(double x, double y, double z);
Point3D makePoint3D();

void setPoint3D(Point3D &aPoint, double x, double y, double z)
{
    aPoint.x = x;
    aPoint.y = y;
    aPoint.z = z;
}

void addPoint3D(Point3D &aPoint, double x, double y, double z)
{
    aPoint.x += x;
    aPoint.y += y;
    aPoint.z += z;
}

void mulPoint3D(Point3D &aPoint, double x, double y, double z)
{
    aPoint.x *= x;
    aPoint.y *= y;
    aPoint.z *= z;
}

void mulPoint3DMatrix(Point3D &aPoint, Matrix aMatrix)
{
    Matrix pointMatrix;
    fillMatrix(pointMatrix, 1, 3, 0.);
    pointMatrix.matrixElements[0][0] = aPoint.x;
    pointMatrix.matrixElements[1][0] = aPoint.y;
    pointMatrix.matrixElements[2][0] = aPoint.z;

    Matrix resMatrix;
    mulMatrix(resMatrix, pointMatrix, aMatrix);
    aPoint.x = resMatrix.matrixElements[0][0];
    aPoint.x = resMatrix.matrixElements[1][0];
    aPoint.x = resMatrix.matrixElements[2][0];
}
