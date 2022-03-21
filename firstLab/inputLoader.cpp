#include "inputLoader.h"

#include <fstream>

int load_from_file(figure_t &figure, const char *file_name)
{
    int rc = SUCCESS;
    FILE *input_file = fopen(file_name, "r");
    if (input_file == NULL)
    {
        rc = FILE_ERROR;
    }
    else
    {
        figure_t tmp_figure;
        int point_count = 0;
        rc = (rc != 0) ? rc : file_line_count(point_count, input_file);
        rc = (rc != 0) ? rc : init_links_matrix(tmp_figure, point_count);
        for (int i = 0; rc == SUCCESS && i < point_count; i++)
        {
            double x, y, z;
            rc = (rc == 0) && fscanf(input_file, "%lf %lf %lf -> ", &x, &y, &z) == 3 ? SUCCESS : INPUT_ERROR;
            rc = (rc != 0) ? rc : add_point_to_figure(tmp_figure, x, y, z);
            
            int cur_link;
            while (fscanf(input_file, "%d", &cur_link) == 1)
            {
                rc = (rc != 0) ? rc : add_link_to_figure(tmp_figure, i, cur_link - 1);
            }
            while (!feof(input_file) && fgetc(input_file) != '\n');
        }
        if (rc == SUCCESS)
        {
            rc = figure_copy(figure, tmp_figure);
        }
    }
    return rc;
}

int file_line_count(int &point_count, FILE *file)
{
    int rc = SUCCESS;
    if (file == NULL)
    {
        rc = FILE_ERROR;
    }
    else
    {
        rewind(file);
        point_count = 0;
        char *msg = NULL;
        size_t msg_count = 0;
        while(getline(&msg, &msg_count, file) != -1)
        {
            ++point_count;   
        }
        free(msg);
    }
    rewind(file);
    return rc;
}
