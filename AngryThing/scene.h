#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <gameitem.h>

using namespace std;

class Scene : public QGraphicsScene
{
public:
    Scene(QObject* parent = 0);
    void repaint();
    /* Location data */
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

    /* Line Item */
    QGraphicsLineItem *upper_line;
    QGraphicsLineItem *lower_line;

    /* BackGround */
    gameItem *bg;
    QString bg_path;
    /* Game obj */
    gameItem *bird1;
    QString bird1_path;
    /* FIXME : need to change catapult class */
    gameItem *catapult_upper;
    QString cata_up_path;
    gameItem *catapult_lower;
    QString cata_lo_path;
    gameItem *bucket;
    QString bucket_path;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
