#include "scene.h"

Scene::Scene(qreal screenS_x, qreal screenS_y , QObject *parent): QGraphicsScene(parent)
{
    /* Initial the boundary */
    screenSize_x = screenS_x;
    screenSize_y = screenS_y;

    QImage temp_img;
    /* Initialize the catapult */
    cata_up_path = "../angrything_img_src/object/Catapult_upper.png";
    temp_img.load(cata_up_path);
    temp_img = temp_img.scaled(50,130,Qt::KeepAspectRatio);
    catapult_upper = new gameItem(screenSize_x,screenSize_y);
    catapult_upper->status = 1;
    catapult_upper->setPixmap(QPixmap::fromImage(temp_img));
    addItem(catapult_upper);
    catapult_upper->setPos(62,380);
    catapult_upper->setZValue(10);

    cata_lo_path = "../angrything_img_src/object/Catapult_lower.png";
    temp_img.load(cata_lo_path);
    temp_img = temp_img.scaled(90,150,Qt::KeepAspectRatio);
    catapult_lower = new gameItem(screenSize_x,screenSize_y);
    catapult_lower->status = 1;
    catapult_lower->setPixmap(QPixmap::fromImage(temp_img));
    addItem(catapult_lower);
    catapult_lower->setPos(60,370);
    catapult_lower->setZValue(5);

    /* Initialize the bucket */
    bucket_path = "../angrything_img_src/object/Bucket.png";
    temp_img.load(bucket_path);
    temp_img = temp_img.scaled(30,30,Qt::KeepAspectRatio);
    bucket = new gameItem(screenSize_x,screenSize_y);
    bucket->status = 1;
    bucket->setPixmap(QPixmap::fromImage(temp_img));
    addItem(bucket);
    bucket_x = 40;
    bucket_y = 425;
    bucket->setPos(40,425);
    bucket->setRotation(-40);

    /* Initialize the bird1 */
    bird1_path = "../angrything_img_src/object/Normal_Bird_1.png";
    temp_img.load(bird1_path);
    temp_img = temp_img.scaled(50,50,Qt::KeepAspectRatio);
    bird1 = new gameItem(screenSize_x,screenSize_y);
    bird1->status = 1;
    bird1->setPixmap(QPixmap::fromImage(temp_img));
    bird1->setZValue(7);
    addItem(bird1);
    shooting_item_x = 45;
    shooting_item_y = 380;
    bird1->setPos(shooting_item_x,shooting_item_y);

    /* Setting the line */
    upper_line_start_x = 55;
    upper_line_start_y = 430;
    upper_line = new QGraphicsLineItem();
    upper_line->setPen(QPen(Qt::black,8,Qt::SolidLine));
    upper_line->setLine(65,400,upper_line_start_x,upper_line_start_y);
    upper_line->setZValue(9);

    lower_line_start_x = 55;
    lower_line_start_y = 430;
    lower_line = new QGraphicsLineItem();
    lower_line->setPen(QPen(Qt::black,8,Qt::SolidLine));
    lower_line->setLine(100,400,lower_line_start_x,lower_line_start_y);
    lower_line->setZValue(6);
    addItem(lower_line);
    addItem(upper_line);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(advance()));
    timer->start(100);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* For debugging  */
    bird1->setPos(shooting_item_x,shooting_item_y);

    mouse_start_x = event->scenePos().x();
    mouse_start_y = event->scenePos().y();
    cout<< "x: " << mouse_start_x << " compare x Bound : "<< screenSize_x << " y: " << mouse_start_y << " compare y bound : "<< screenSize_y << endl;
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //cout << "Moving x :" << event->scenePos().x() << endl;
    //cout << "Moving y :" << event->scenePos().y() << endl;
    //bird1->setPos(event->scenePos().x(),event->scenePos().y());
    /* FIXME : need function to select the shooting bird */
    qreal now_mouse_x = event->scenePos().x();
    qreal now_mouse_y = event->scenePos().y();

    qreal dist_x = now_mouse_x - mouse_start_x;
    qreal dist_y = now_mouse_y - mouse_start_y;

    /* Adjust the Move : bird1 and  bucket (together)*/
    bird1->setPos(shooting_item_x+dist_x/3,shooting_item_y+dist_y/3);
    bucket->setPos(bucket_x+dist_x/3,bucket_y+dist_y/3);

    /* Adjust the line */
    upper_line->setLine(65,400,upper_line_start_x+dist_x/3,upper_line_start_y+dist_y/3);
    lower_line->setLine(100,400,lower_line_start_x+dist_x/3,lower_line_start_y+dist_y/3);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //cout << "Release !" << endl;
    //shooting_item_x = bird1->pos().x();
    //shooting_item_y = bird1->pos().y();
    /*
    bucket_x = bucket->pos().x();
    bucket_y = bucket->pos().y();
    upper_line_start_x = bucket_x+10;//event->scenePos().x();
    upper_line_start_y = bucket_y;//event->scenePos().y();
    lower_line_start_x = bucket_x+10;
    lower_line_start_y = bucket_y;
    */
    bucket->setPos(bucket_x,bucket_y);
    upper_line->setLine(65,400,upper_line_start_x,upper_line_start_y);
    lower_line->setLine(100,400,lower_line_start_x,lower_line_start_y);
    /* Give bird a speed to fly , and set it's status to free object */
    bird1->status = 0;
    bird1->speed_x = 20;
    bird1->speed_y = -10;
}

