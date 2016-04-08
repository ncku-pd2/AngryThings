#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int width, int height,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	setFixedSize(width,height);
    screenWidth = width;
    screenHeight = height;
    // setting the scene size
	scene = new Scene(screenWidth , scre    // Program LoopenHeight ,parent);
    scene->setSceneRect(10,25,screenWidth,screenHeight);
    // Put scene in graphicsView
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
	settingBackground(width,height);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBackground(int bgw,int bgh)
{
    QImage bg;
    bg.load("../angrything_img_src/background/Sky_1.png");
    bg= bg.scaled(bgw,bgh,Qt::KeepAspectRatio);
    ui->graphicsView->setBackgroundBrush(bg);
}

void MainWindow::settingInitObj()
{
    /* Debugging */
    /*QList<QGraphicsItem *> list = scene->collidingItems(catapult_upper);
    foreach (QGraphicsItem *i, list) {
        gameItem *item = dynamic_cast<gameItem *>(i);
        cout << item->zValue() << endl;
    }
    */
}

