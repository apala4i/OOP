#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputLoader.h"
#include "affine_transform.h"
#include "figure.h"
#include <QApplication>
#include <iostream>

#include "controller.h"
#include "error_show.h"

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
    data_t data = {.file_path = (char *)FILE_PATH};
    int rc = make_action(data, LOAD_FIGURE);
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
    bool first_correct = false;
    bool second_correct = false;
    bool third_correct = false;
    double x = ui->lineEdit_4->text().toDouble(&first_correct);
    double y = ui->lineEdit_5->text().toDouble(&second_correct);
    double z = ui->lineEdit_6->text().toDouble(&third_correct);
    point_3D_t scale;
    set_point_3D(scale, x, y, z);
    data_t data = {.scale_values = scale};

    int rc = first_correct && second_correct && third_correct ? make_action(data, SCALE) : BAD_DATA;
    if (rc == SUCCESS)
    {
        update_figure(this);
    }
    else
    {
        show_error(this, rc);
    }
}

void update_figure(QMainWindow *window)
{
    int rc = SUCCESS;
    figure_t figure;
    data_t data;
    data.figure = figure;
    rc = rc == SUCCESS ? make_action(data, GET_FIGURE) : rc;
    if (rc != SUCCESS)
    {
        show_error(window, rc);
    }
    else
    {
        repaint_figure(data.figure);
    }
    free_figure(data.figure);
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
    bool first_correct = false;
    bool second_correct = false;
    bool third_correct = false;
    double x = ui->lineEdit_7->text().toDouble(&first_correct);
    double y = ui->lineEdit_15->text().toDouble(&second_correct);
    double z = ui->lineEdit_14->text().toDouble(&third_correct);
    set_point_3D(rotate, x, y, z);
    data_t data;
    data.angles_values = rotate;

    rc = first_correct && second_correct && third_correct ? make_action(data, ROTATE) : BAD_DATA;
    if (rc == SUCCESS)
    {
        update_figure(this);
    }
    else
    {
        show_error(this, rc);
    }
}


// translate
void MainWindow::on_pushButton_5_clicked()
{
    bool first_correct = false;
    bool second_correct = false;
    bool third_correct = false;
    double x = ui->lineEdit_11->text().toDouble(&first_correct);
    double y = ui->lineEdit_9->text().toDouble(&second_correct);
    double z = ui->lineEdit_10->text().toDouble(&third_correct);

    int rc = first_correct && second_correct && third_correct ? SUCCESS : BAD_DATA;

    if (rc == SUCCESS)
    {
        point_3D_t translate_vector;
        set_point_3D(translate_vector, x, y, z);
        data_t data = {.translate_values = translate_vector};

        int rc = make_action(data, TRANSLATE);
        if (rc == SUCCESS)
        {
            update_figure(this);
        }
    }

    if (rc != SUCCESS)
    {
        show_error(this, rc);
    }

}


// clear canvas
void MainWindow::on_pushButton_7_clicked()
{
    int rc = SUCCESS;
    data_t data;
    rc = make_action(data, FREE_FIGURE);
    if (rc != SUCCESS)
    {
        show_error(this, rc);
    }
    scene->clear();
}


// change center
void MainWindow::on_pushButton_2_clicked()
{
    bool first_correct = false;
    bool second_correct = false;
    bool third_correct = false;
    double x = ui->lineEdit_13->text().toDouble(&first_correct);
    double y = ui->lineEdit_8->text().toDouble(&second_correct);
    double z = ui->lineEdit_12->text().toDouble(&third_correct);

    int rc = first_correct && second_correct && third_correct ? SUCCESS : BAD_DATA;
    point_3D_t new_center;
    set_point_3D(new_center, x, y, z);
    data_t data = {.center_values = new_center};
    rc = rc == SUCCESS ? make_action(data, SET_CENTER) : rc;
    if (rc != SUCCESS)
    {
        show_error(this, rc);
    }
}

