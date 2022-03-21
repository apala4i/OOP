#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputLoader.h"
#include "affine_transform.h"
#include "figure.h"
#include <QApplication>
#include <iostream>

#include "controller.h"
#include "error_show.h"

static figure_t main_figure;
static QGraphicsScene *scene;

int draw_point(const point_3D_t point);

int draw_figure_points(const figure_t &figure);

int draw_figure_links(const figure_t &figure);

void update_figure(QMainWindow *window);

void repaint_figure(figure_t figure);

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


// load figure
void MainWindow::on_pushButton_6_clicked()
{
    int rc = make_action(LOAD_FIGURE);
    if (rc == SUCCESS)
    {
        update_figure(this);
    }
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
        for (int i = 0; i < get_size_point_array(figure.points); ++i)
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


// scale
void MainWindow::on_pushButton_3_clicked()
{
    point_3D_t scale;
    double x = ui->lineEdit_4->text().toDouble();
    double y = ui->lineEdit_5->text().toDouble();
    double z = ui->lineEdit_6->text().toDouble();
    set_point_3D(scale, x, y, z);

    int rc = make_action(SCALE, scale);
    if (rc == SUCCESS)
    {
        update_figure(this);
    }
}

void update_figure(QMainWindow *window)
{
    int rc = SUCCESS;
    figure_t figure;
    rc = rc == SUCCESS ? make_action(GET_FIGURE, figure) : rc;
    if (rc != SUCCESS)
    {
        show_error(window, rc);
    }
    else
    {
        repaint_figure(figure);
    }
    free_figure(figure);
}

void repaint_figure(figure_t figure)
{
    scene->clear();
    draw_figure(figure);
}


// rotate
void MainWindow::on_pushButton_4_clicked()
{
    int rc = SUCCESS;
    point_3D_t rotate;
    double x = ui->lineEdit_7->text().toDouble();
    double y = ui->lineEdit_15->text().toDouble();
    double z = ui->lineEdit_14->text().toDouble();
    set_point_3D(rotate, x, y, z);

    rc = make_action(ROTATE, rotate);
    if (rc == SUCCESS)
    {
        update_figure(this);
    }
}


// translate
void MainWindow::on_pushButton_5_clicked()
{
    point_3D_t translate_vector;
    double x = ui->lineEdit_11->text().toDouble();
    double y = ui->lineEdit_9->text().toDouble();
    double z = ui->lineEdit_10->text().toDouble();
    set_point_3D(translate_vector, x, y, z);

    int rc = make_action(TRANSLATE, translate_vector);
    if (rc == SUCCESS)
    {
        update_figure(this);
    }

}


// clear canvas
void MainWindow::on_pushButton_7_clicked()
{
    scene->clear();
}


// change center
void MainWindow::on_pushButton_2_clicked()
{
    double x = ui->lineEdit_13->text().toDouble();
    double y = ui->lineEdit_8->text().toDouble();
    double z = ui->lineEdit_12->text().toDouble();

    point_3D_t new_center;
    set_point_3D(new_center, x, y, z);

    int rc = make_action(SET_CENTER,  new_center);
    if (rc != SUCCESS)
    {
        show_error(this, rc);
    }
}

