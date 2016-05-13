#ifndef SPEEDBIRD_H
#define SPEEDBIRD_H
#include <bird.h>

class SpeedBird : public Bird
{
public:
    SpeedBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void paint();
public slots:
    void click();
};

#endif // SPEEDBIRD_H
