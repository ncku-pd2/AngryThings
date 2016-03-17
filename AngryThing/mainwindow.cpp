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
    scene = new QGraphicsScene(-10,-10,screenWidth,screenHeight);
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
    QImage temp_img;
    /* Initialize the catapult */
    cata_up_path = "../angrything_img_src/object/Catapult_upper.png";
    temp_img.load(cata_up_path);
    temp_img = temp_img.scaled(50,130,Qt::KeepAspectRatio);
    catapult_upper = new gameItem();
    catapult_upper->setPixmap(QPixmap::fromImage(temp_img));
    scene->addItem(catapult_upper);
    catapult_upper->setPos(62,380);
    catapult_upper->setZValue(99);
    cout << catapult_upper->zValue() << endl;
    cata_lo_path = "../angrything_img_src/object/Catapult_lower.png";
    temp_img.load(cata_lo_path);
    temp_img = temp_img.scaled(90,150,Qt::KeepAspectRatio);
    catapult_lower = new gameItem();
    catapult_lower->setPixmap(QPixmap::fromImage(temp_img));
    scene->addItem(catapult_lower);
    catapult_lower->setPos(60,370);
    /* Initialize the bird1 */
    bird1_path = "../angrything_img_src/object/Normal_Bird_1.png";
    temp_img.load(bird1_path);
    temp_img = temp_img.scaled(50,50,Qt::KeepAspectRatio);
    bird1 = new gameItem();
    bird1->setPixmap(QPixmap::fromImage(temp_img));
    scene->addItem(bird1);
    bird1->setPos(500,350);
    bird1->setFlag(QGraphicsItem::ItemIsMovable);
    cout << bird1->zValue() << endl;
    /* Initialize the bird2 */

}
