#include "controller.h"
#include "actions.h"

int make_action(data_t &data, const ACTIONS action)
{
    static figure_t figure;

    int rc = SUCCESS;
    switch (action)
    {
        case ROTATE:
            rc = rotate_figure(figure, data.angles_values);
            break;
        case TRANSLATE:
            rc =  translate_figure(figure, data.translate_values);
            break;
        case SCALE:
            rc = scale_figure(figure, data.scale_values);
            break;
        case SET_CENTER:
            rc = set_center(figure, data.center_values);
            break;
        case GET_FIGURE:
            rc = get_figure(data.figure, figure);
            break;
        case LOAD_FIGURE:
            rc = load_figure(figure, data.file_path);
            break;
        case FREE_FIGURE:
            rc = free_figure(figure);
            break;
        default:
            rc = BAD_ARG_ERROR;
            break;
    }
    return rc;
}
