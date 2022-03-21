#ifndef ERROR_SHOW_H
#define ERROR_SHOW_H
#include <QMessageBox>
#include <QMainWindow>

#include <string>

QString error_type_to_string(const int error_type);

void show_error(QMainWindow *window, const int error_type);

#endif // ERROR_SHOW_H
