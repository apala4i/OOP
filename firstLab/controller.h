﻿#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "point3d.h"
#include "figure.h"
#include "affine_transform.h"
#include "loader.h"

#define FILE_PATH "D:\\VUZ\\OOP\\lab_01_\\OOP\\firstLab\\test.txt"


typedef enum
{
    ROTATE,
    TRANSLATE,
    SCALE,
    SET_CENTER,
    GET_FIGURE,
    LOAD_FIGURE,
    UNKNOWN
}ACTIONS;

int make_action(const ACTIONS action, const point_3D_t value);

int make_action(const ACTIONS action);

int make_action(figure_t &dst, const ACTIONS action);

int rotate_figure(const point_3D_t values);

int translate_figure(const point_3D_t values);

int scale_figure(const point_3D_t value);

int init_figure();

int set_center(const point_3D_t new_center);

#endif
