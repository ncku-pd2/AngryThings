#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    // Set the scene's bg
    QImage bg;
    bg.load(":/sky_complete.png");
    // To show the grass , we need to -30
    bg = bg.scaled(width(),ui->graphicsView->height()-30,Qt::KeepAspectRatio);
    scene->setBackgroundBrush(bg);
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    // Create bird
    Bird *birdie = new Bird(0.0f,10.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie->setLinearVelocity(b2Vec2(5,5));
    itemList.push_back(birdie);
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(100/6);
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}
