#ifndef GAMEITEM_H
#define GAMEITEM_H
#include <QGraphicsPixmapItem>

class gameItem : public QGraphicsPixmapItem
{
public:
    gameItem(qreal size_x , qreal size_y);
    void advance(int phase);
    void checkBoundary();
    qreal upperBound;
    qreal lowerBound;
    qreal leftBound;
    qreal rightBound;
    /* Physical variable */
    qreal speed_x;
    qreal speed_y;

    qreal grav_accel;
    qreal x_accel;
    qreal y_accel;

    qreal screenSize_x;
    qreal screenSize_y;

    /* Define the object status => FIXME : using polymorphism */
    /* 0 for movable object , 1 for static object */
    int status;
};

#endif // GAMEITEM_H
