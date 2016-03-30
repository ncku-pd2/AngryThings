#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(qreal width, qreal height, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    x_sceneSize = width-200;
    y_sceneSize = height-100;
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,x_sceneSize,y_sceneSize);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
