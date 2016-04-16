#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <gameitem.h>
#include <QTimer>
#include <math.h>

#include "pixmapitem.h"
#include "bird.h"
#include "enemy.h"

using namespace std;

class Scene : public QGraphicsScene
{
	Q_OBJECT
public:
    Scene(qreal screenS_x, qreal screenS_y ,QObject* parent = 0);
    void createEnemy(int num);
    void randomGenerateLocation(Enemy *item, int up ,int down ,int left , int right);
    /* Object Location data */
    qreal shooting_item_x;
    qreal shooting_item_y;
    qreal bucket_x;
    qreal bucket_y;
    qreal mouse_start_x;
    qreal mouse_start_y;
    qreal upper_line_start_x;
    qreal upper_line_start_y;
    qreal lower_line_start_x;
    qreal lower_line_start_y;

    qreal boundary_up;
    qreal boundary_bot;
    qreal boundary_left;
    qreal boundary_right;

    qreal screenSize_x;
    qreal screenSize_y;
    /* Line Item */
    QGraphicsLineItem *upper_line;
    QGraphicsLineItem *lower_line;
    /* BackGround */
	//gameItem *bg;
	//QString bg_path;
    /* Game obj */
	bird *bird1;
    QString bird1_path;
    /* FIXME : need to change catapult class */
	PixmapItem *catapult_upper;
    gameItem *catapult_lower;
    gameItem *bucket;
    QString bucket_path;

    /* Obstacle */
    QList<Enemy *> enemyList;
    QString pig_path;

    /* QTimer */
    QTimer *timer;

public slots:
	void collition();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *);

};

#endif // SCENE_H
