#ifndef ACTIONS_H
#define ACTIONS_H
#include "figure.h"
#include "point3d.h"
#include "mainwindow.h"

int rotate_figure(figure_t &figure, const point_3D_t values);

int translate_figure(figure_t &figure, const point_3D_t values);

int scale_figure(figure_t &figure, const point_3D_t value);

int init_figure(figure_t &figure);

int set_center(figure_t &figure, const point_3D_t new_center);

int load_figure(figure_t &figure, char *file_path);

int get_figure(model_t &dst, const figure_t &figure);

#endif
