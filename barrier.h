#ifndef BARRIER_H
#define BARRIER_H

#include <gameitem.h>
#include <QGraphicsScene>
#include <QTimer>

#define BARRIER_DENSITY 5.0f
#define BARRIER_FRICTION 0.7f
#define BARRIER_RESTITUTION 0.1f

class Barrier : public GameItem
{
public:
    Barrier(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void paint();
    void collide();
};

#endif // BARRIER_H
