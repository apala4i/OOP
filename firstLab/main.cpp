#include "mainwindow.h"
#include "matrix.h"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    struct matrix matrix;
    init_matrix(matrix, 10, 10);
    print_matrix(matrix);


}
