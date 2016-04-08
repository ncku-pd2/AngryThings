#ifndef GAMEITEM_H
#define GAMEITEM_H
#include <QGraphicsPixmapItem>

class gameItem : public QGraphicsPixmapItem
{

public:
    /* Constructor */
	gameItem(qreal size_x , qreal size_y);
    /* Check boundary */
	virtual void advance(int);
	virtual bool checkBoundary();
	/* Game scene size
    qreal screenSize_x;
    qreal screenSize_y;
	/* Game scene Boundary*/
    qreal upperBound;
    qreal lowerBound;
    qreal leftBound;
    qreal rightBound;
	/* Physical variable
    qreal speed_x;
    qreal speed_y;
    qreal grav_accel; // Gravity
    qreal x_accel; // x-axis acceleration
    qreal y_accel; // y-axis acceleration
    /* 0 for movable object , 1 for static object */
	//int status;
};

#endif // GAMEITEM_H
