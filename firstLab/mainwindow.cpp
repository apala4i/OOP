#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputLoader.h"
#include "figure.h"
#include <QApplication>


figure_t main_figure;
QGraphicsScene *scene;

int draw_point(const point_3D_t point);

int draw_figure_points(const figure_t &figure);

int draw_figure_links(const figure_t &figure);

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
    for (int i = 0; i < figure.links.columns; ++i)
    {
        for (int j = 0; j < figure.links.columns; ++j)
        {
            if (figure.links.matrix_elements[i][j] > 0.0001)
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

