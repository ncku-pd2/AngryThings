#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event filter
    qApp->installEventFilter(this);
    mouseEventMode = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    scene->setBackgroundBrush(QImage(":/sky_complete.png").scaled(width(),ui->graphicsView->height()-30,Qt::KeepAspectRatio));
    ui->graphicsView->setScene(scene);
    // Draw Statics Picture
    setCatapult();

    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    // Create bird
    birdie = new Bird(3.0f,6.0f,0.225f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie->g_pixmap.setZValue(3);
    itemList.push_back(birdie);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress && mouseEventMode == 0)
    {
        // dynamic cast the event
        QMouseEvent *nowPos = dynamic_cast<QMouseEvent *>(event);
        mouseEventMode = 1;
        birdie->g_pixmap.setPos(bird_start.x() , bird_start.y() - 25);
        timer.stop();
        // Get the start position
        mouse_start = QPoint(nowPos->screenPos().x(), nowPos->screenPos().y());
    }
    if(event->type() == QEvent::MouseMove && mouseEventMode == 1)
    {
        QMouseEvent *nowPos = dynamic_cast<QMouseEvent *>(event);
        QPointF dist_pos(nowPos->screenPos().x() - mouse_start.x(), nowPos->screenPos().y() - mouse_start.y());
        birdie->g_pixmap.setPos(bird_start.x()+dist_pos.x()/3 , (bird_start.y()-25)+dist_pos.y()/3);
        bucket->setPos(bird_start.x()+dist_pos.x()/3,bird_start.y()+dist_pos.y()/3);
        line1->setLine(170,330,line_end.x()+dist_pos.x()/3,line_end.y()+dist_pos.y()/3);
        line2->setLine(210,330,line_end.x()+dist_pos.x()/3,line_end.y()+dist_pos.y()/3);
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        mouseEventMode = 0;
        // Get the bird speed to shoot
        birdie->startShoot();
        // Get the current bird pos , and get the speed
        birdie->setLinearVelocity(b2Vec2(-(birdie->g_pixmap.pos().x() - bird_start.x())/2,(birdie->g_pixmap.pos().y() - (bird_start.y()-25))/2));
        bucket->setPos(bird_start.x(),bird_start.y());
        line1->setLine(170,330,line_end.x(),line_end.y());
        line2->setLine(210,330,line_end.x(),line_end.y());
        timer.start();
    }
    return false;
}


void MainWindow::setCatapult()
{
    // Add the pure pixmap into scene
    // Add upper catapult
    QGraphicsPixmapItem *cata_upper = new QGraphicsPixmapItem();
    cata_upper->setPixmap(QPixmap(":/cata_upper.png").scaled(60,130,Qt::IgnoreAspectRatio));
    cata_upper->setPos(155,310);
    cata_upper->setZValue(4);
    scene->addItem(cata_upper);

    QGraphicsPixmapItem *cata_lower = new QGraphicsPixmapItem();
    cata_lower->setPixmap(QPixmap(":/cata_lower.png").scaled(70,150,Qt::IgnoreAspectRatio));
    cata_lower->setPos(150,300);
    cata_lower->setZValue(2);
    scene->addItem(cata_lower);

    // and then add bucket + line control
    bucket = new QGraphicsPixmapItem();
    bucket->setPixmap(QPixmap(":/bucket.png").scaled(30,30,Qt::KeepAspectRatio));
    bucket->setPos(95,370);
    bird_start = QPoint(95,370);
    bucket->setRotation(-30);
    bucket->setZValue(5);
    scene->addItem(bucket);

    // Setting the line
    line_end = QPoint(110,375);
    line1 = new QGraphicsLineItem();
    line1->setPen(QPen(Qt::black,8,Qt::SolidLine));
    line1->setLine(170,330,line_end.x(),line_end.y());
    line1->setZValue(4);
    scene->addItem(line1);

    line2 = new QGraphicsLineItem();
    line2->setPen(QPen(Qt::black,8,Qt::SolidLine));
    line2->setLine(210,330,line_end.x(),line_end.y());
    line2->setZValue(1);
    scene->addItem(line2);
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}
