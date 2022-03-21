#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputLoader.h"
#include "affine_transform.h"
#include "figure.h"
#include <QApplication>
#include <iostream>


static figure_t main_figure;
static QGraphicsScene *scene;

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
    load_from_file(main_figure, "D:\\VUZ\\OOP\\lab_01_\\OOP\\firstLab\\test.txt");
    // print_figure(stdout, main_figure);
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
    if (figure.points.size == 0)
    {
        rc = EMPTY_DATA_ERROR;
    }
    else
    {
        for (int i = 0; i < figure.points.size; ++i)
        {
            draw_point(figure.points.array[i]);
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
                scene->addLine(figure.points.array[i].x, figure.points.array[i].y, figure.points.array[j].x, figure.points.array[j].y);
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
    point_3D_t scale;
    double x = ui->lineEdit_4->text().toDouble();
    double y = ui->lineEdit_5->text().toDouble();
    double z = ui->lineEdit_6->text().toDouble();
    set_point_3D(scale, x, y, z);
    matrix_t matrix;

    scale_matrix(matrix, scale, main_figure.figure_center);
    add_transformation(main_figure, matrix);
    free_matrix(matrix);
    // print_figure(stdout, main_figure);
    scene->clear();
    draw_figure(main_figure);

}

void MainWindow::on_pushButton_4_clicked()
{
    point_3D_t rotate;
    double x = ui->lineEdit_7->text().toDouble();
    double y = ui->lineEdit_15->text().toDouble();
    double z = ui->lineEdit_14->text().toDouble();
    set_point_3D(rotate, x, y, z);
    matrix_t matrix;
    rotate_matrix(matrix, rotate, main_figure.figure_center);


    add_transformation(main_figure, matrix);
    free_matrix(matrix);

    // print_figure(stdout, main_figure);
    scene->clear();
    draw_figure(main_figure);
}

void MainWindow::on_pushButton_5_clicked()
{
    point_3D_t translate_vector;
    double x = ui->lineEdit_11->text().toDouble();
    double y = ui->lineEdit_9->text().toDouble();
    double z = ui->lineEdit_10->text().toDouble();
    set_point_3D(translate_vector, x, y, z);
    matrix_t matrix;

    translate_matrix(matrix, translate_vector);


    add_transformation(main_figure, matrix);
    free_matrix(matrix);
    // print_figure(stdout, main_figure);
    scene->clear();
    draw_figure(main_figure);
}

void MainWindow::on_pushButton_7_clicked()
{
    scene->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    double x = ui->lineEdit_13->text().toDouble();
    double y = ui->lineEdit_8->text().toDouble();
    double z = ui->lineEdit_12->text().toDouble();
    set_point_3D(main_figure.figure_center, x, y, z);
}

