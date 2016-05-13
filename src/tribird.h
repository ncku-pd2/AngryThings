#ifndef TRIBIRD_H
#define TRIBIRD_H
#include <bird.h>
#include <QList>

class TriBird : public Bird
{
public:
    TriBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene, bool mainB = true);
    static void clearBuffer();
public slots:
    void click();
private:
    QTimer *timer;
    QGraphicsScene *scene;
    b2World *world;
    float radius;
    QPixmap pixmap;
    bool mainTri,mainClicked;
    static QList<TriBird *> triList;

};

#endif // TRIBIRD_H
