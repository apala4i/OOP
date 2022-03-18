#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include "point3d.h"
#include "matrix.h"

struct Figure
{
    std::vector<Point3D> Points;
    Point3D figureCenter;
};

void addTransformation(Figure &aFigure, Matrix &transformation);


#endif // FIGURE_H
