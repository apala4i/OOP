#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "point3d.h"
#include "figure.h"
#include "affine_transform.h"
#include "inputLoader.h"

typedef struct data
{
    point_3D_t angles_values = {0, 0, 0};
    point_3D_t scale_values = {1, 1, 1};
    point_3D_t translate_values = {0, 0, 0};
    point_3D_t center_values = {0, 0, 0};
    figure_t figure;
    char *file_path;
}data_t;


typedef enum
{
    ROTATE,
    TRANSLATE,
    SCALE,
    SET_CENTER,
    GET_FIGURE,
    LOAD_FIGURE,
    FREE_FIGURE,
    UNKNOWN
}ACTIONS;

int make_action(data_t &data, const ACTIONS action);

#endif
