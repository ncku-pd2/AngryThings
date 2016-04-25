#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.3f
#define BIRD_RESTITUTION 0.5f

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void startShoot();
    void setLinearVelocity(b2Vec2 velocity);
    float x_pos;
    float y_pos;
    float r;
    b2World *w;
};

#endif // BIRD_H
