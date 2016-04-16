#ifndef ENEMY_H
#define ENEMY_H

#include "gameitem.h"

class Enemy : public gameItem
{
public:
    Enemy(qreal size_x, qreal size_y , int w , int h);
    void advance(int);
    bool checkBoundary();

    /* Physical variable */
    qreal speed_x;
    qreal speed_y;
    qreal grav_accel; // Gravity
    qreal x_accel; // x-axis acceleration
    qreal y_accel; // y-axis acceleration

    int width;
    int height;

    bool allowPhysic;
};

#endif // ENEMY_H
