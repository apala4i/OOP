#include "figure.h"

void addTransformation(Figure &aFigure, Matrix &transformation)
{
    for (size_t i = 0; i < aFigure.Points.size(); ++i)
    {
        mulPoint3DMatrix(aFigure.Points[i], transformation);
    }
}
