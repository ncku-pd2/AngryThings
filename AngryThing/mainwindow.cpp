#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int width, int height,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    screenWidth = width;
    screenHeight = height;
    // setting the scene size
    scene = new Scene(parent);
    //scene = new QGraphicsScene(-10,-10,screenWidth,screenHeight);
    scene->setSceneRect(10,25,screenWidth,screenHeight);
    // Put scene in graphicsView
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
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

    //cout << bird1->zValue() << endl;
    /* Initialize the bird2 */

    /* Debugging */
    /*QList<QGraphicsItem *> list = scene->collidingItems(catapult_upper);
    foreach (QGraphicsItem *i, list) {
        gameItem *item = dynamic_cast<gameItem *>(i);
        cout << item->zValue() << endl;
    }
    */

    /* Bucket line */
    /*QPen pen(Qt::black,8);
    QLineF line(65,400,55,430);
    scene->addLine(line , pen);*/
}

