#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.7f
#define BIRD_RESTITUTION 0.3f

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void startShoot();
    void setLinearVelocity(b2Vec2 velocity);
    void paint();
    void collide();
    float x_pos;
    float y_pos;
    float radius;
    b2World *world;
    QTimer *timer;
};

#endif // BIRD_H
