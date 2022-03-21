#include "error_show.h"
#include "errors.h"
#include <QMessageBox>

QString error_type_to_string(const int error_type)
{
    switch (error_type)
    {
    case SIZE_ERROR:
        return "SIZE_ERROR";
        break;
    case MALLOC_ERROR:
        return "MALLOC_ERROR";
        break;
    case EMPTY_DATA_ERROR:
        return "EMPTY_DATA_ERROR";
        break;
    case BAD_ARG_ERROR:
        return "BAD_ARG_ERROR";
        break;
    case SCALE_COEF_ERROR:
        return "SCALE_COEF_ERROR";
        break;
    case INDEX_OUT_OF_RANGE:
        return "INDEX_OUT_OF_RANGE";
        break;
    case BAD_DATA:
        return "BAD_DATA";
        break;
    case FILE_ERROR:
        return "FILE_ERROR";
        break;
    case INPUT_ERROR:
        return "INPUT_ERROR";
        break;
    case EMPTY_FIGURE:
        return "EMPTY_FIGURE";
        break;
    case WRONG_COMMAND:
        return "WRONG_COMMAND";
    default:
        return QString::fromStdString("UNKNOWN_ERROR");
    }
}

void show_error(QMainWindow *window, const int error_type)
{
    QMessageBox::warning(window, "Error", error_type_to_string(error_type));
}
