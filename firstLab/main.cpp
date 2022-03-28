#include "mainwindow.h"
#include "matrix.h"
#include "figure.h"
#include "loader.h"
#include <cstdio>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    figure_t figure;
}
