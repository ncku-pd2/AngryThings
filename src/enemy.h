#ifndef ENEMY_H
#define ENEMY_H
#include <gameitem.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.7f
#define BIRD_RESTITUTION 0.3f

class Enemy : public GameItem
{
public:
    Enemy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    ~Enemy();
    void paint();
    void collide();
    QTimer *timer;
    QGraphicsScene *scene;
    bool needDelete;
};

#endif // ENEMY_H
