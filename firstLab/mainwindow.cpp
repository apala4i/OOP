#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputLoader.h"
#include "affine_transform.h"
#include "figure.h"
#include <QApplication>
#include <iostream>


figure_t main_figure;
QGraphicsScene *scene;

int draw_point(const point_3D_t point);

int draw_figure_points(const figure_t &figure);

int draw_figure_links(const figure_t &figure);

point_3D_t scale;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_6_clicked()
{
    load_from_file(main_figure, "/home/chel/2022/University/OOP/lab_01/firstLab/test.txt");
    print_figure(stdout, main_figure);
    draw_figure_points(main_figure);
    draw_figure_links(main_figure);
}

int draw_figure(const figure_t &figure)
{
    int rc = SUCCESS;
    rc = draw_figure_points(figure);
    rc = rc == SUCCESS ? draw_figure_links(figure) : rc;
    return rc;
}

int draw_figure_points(const figure_t &figure)
{
    int rc = SUCCESS;
    if (figure.Points.size == 0)
    {
        rc = EMPTY_DATA_ERROR;
    }
    else
    {
        for (int i = 0; i < figure.Points.size; ++i)
        {
            draw_point(figure.Points.array[i]);
        }
    }
    return rc;
}

int draw_figure_links(const figure_t &figure)
{
    int rc = SUCCESS;
    for (int i = 0; i < figure.links.columns - 1; ++i)
    {
        for (int j = i + 1; j < figure.links.columns; ++j)
        {
            if (figure.links.matrix_elements[i][j] >= 0.0001)
            {
                scene->addLine(figure.Points.array[i].x, figure.Points.array[i].y, figure.Points.array[j].x, figure.Points.array[j].y);
            }
        }
    }
    return rc;
}

int draw_point(const point_3D_t point)
{
    int r = 5;
    scene->addEllipse(point.x - r/2, point.y - r/2, r, r);
    return SUCCESS;
}


void MainWindow::on_pushButton_3_clicked()
{
    matrix_t matrix;
    point_3D_t scale, center;
    set_point_3D(scale, 2, 2, 2);
    set_point_3D(center, 2, 2, 2);
    scale_matrix(matrix, scale, center);
    add_transformation(main_figure, matrix);
    print_figure(stdout, main_figure);
    scene->clear();
    draw_figure(main_figure);

}

void MainWindow::on_pushButton_4_clicked()
{
    matrix_t matrix;
    point_3D_t rotate, center;
    set_point_3D(rotate, 45, 45, 45);
    set_point_3D(center, 2, 2, 2);
    rotate_matrix(matrix, rotate, center);


    add_transformation(main_figure, matrix);
    print_figure(stdout, main_figure);
    scene->clear();
    draw_figure(main_figure);
}

void MainWindow::on_pushButton_5_clicked()
{
    matrix_t matrix;
    point_3D_t translate_vector;
    set_point_3D(translate_vector, 10, 10, 10);
    translate_matrix(matrix, translate_vector);


    add_transformation(main_figure, matrix);
    print_figure(stdout, main_figure);
    scene->clear();
    draw_figure(main_figure);
}

void MainWindow::on_pushButton_7_clicked()
{
    scene->clear();
}


void MainWindow::on_lineEdit_13_textEdited(const QString &arg1)
{
}

