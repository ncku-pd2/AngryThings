#include "scene.h"

Scene::Scene(qreal screenS_x, qreal screenS_y , QObject *parent): QGraphicsScene(parent)
{
    /* Initial the boundary */
    screenSize_x = screenS_x;
    screenSize_y = screenS_y;

    QImage temp_img;
    /* Initialize the catapult */
	catapult_upper = new PixmapItem(
		QPixmap(":/Catapult_upper.png").scaled(50,130,Qt::KeepAspectRatio),
		QPointF(screenSize_x,screenSize_y),
		QPointF(62,380),
		10);
    addItem(catapult_upper);

	catapult_lower = new PixmapItem(
		QPixmap(":/Catapult_lower.png").scaled(90,150,Qt::KeepAspectRatio),
		QPointF(screenSize_x,screenSize_y),
		QPointF(60,370),
		5);
    addItem(catapult_lower);

    /* Initialize the bucket */
	bucket_path = ":/Bucket.png";
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
    timer->start(10);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* For debugging  */
    bird1->setPos(shooting_item_x,shooting_item_y);
    bird1->status = 1;

    mouse_start_x = event->scenePos().x();
    mouse_start_y = event->scenePos().y();
    //cout<< "x: " << mouse_start_x << " compare x Bound : "<< screenSize_x << " y: " << mouse_start_y << " compare y bound : "<< screenSize_y << endl;
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
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

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    bucket->setPos(bucket_x,bucket_y);
    upper_line->setLine(65,400,upper_line_start_x,upper_line_start_y);
    lower_line->setLine(100,400,lower_line_start_x,lower_line_start_y);
    /* Give bird a speed to fly , and set it's status to free object */
    bird1->status = 0;

    bird1->speed_x = (shooting_item_x - bird1->pos().x())/20;
    cout<< shooting_item_x << " ; " << bird1->pos().x() << endl;

    cout<< bird1->speed_x << endl;
    bird1->speed_y = -(bird1->pos().y() - shooting_item_y)/10;
}

