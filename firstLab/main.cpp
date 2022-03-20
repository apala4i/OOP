// #include "mainwindow.h"
#include "matrix.h"
#include "figure.h"
#include "inputLoader.h"
#include <cstdio>

// #include <QApplication>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    figure_t figure;

    load_from_file(figure, "/home/chel/2022/University/OOP/lab_01/firstLab/test.txt");
    print_figure(stdout, figure);
    
    
}
