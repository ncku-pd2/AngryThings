#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>

class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    ~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    b2Body *g_body;
    b2World *g_world;
    QGraphicsPixmapItem g_pixmap;

public slots:
    virtual void paint();
    // virtual void collide();

    static QPointF posb2Toqt(float x, float y);
    static b2Vec2 posqtTob2(float x, float y);
    
protected:
    QSizeF g_size;
    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAMEITEM_H
