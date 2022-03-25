#ifndef LOADER_H
#define LOADER_H


#include "figure.h"
#include "matrix.h"

int load_from_file(figure_t &figure, const char *file_name);

int file_line_count(int &point_count, FILE *file);

#endif // LOADER_H
