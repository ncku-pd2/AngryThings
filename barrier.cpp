#include "barrier.h"

#include <iostream>

Barrier::Barrier(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSizeF(w,h);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    scene->addItem(&g_pixmap);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyBox;
    fixturedef.density = BARRIER_DENSITY;
    fixturedef.friction = BARRIER_FRICTION;
    fixturedef.restitution = BARRIER_RESTITUTION;
    g_body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
}

void Barrier::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    QPointF mappedPoint;
    mappedPoint.setX(((pos.x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    if(g_size.height() < g_size.width()){
        mappedPoint.setY((1.0f - (pos.y-g_size.height()/4)/g_worldsize.height()) * g_windowsize.height());
    }else{
        mappedPoint.setY((1.0f - (pos.y+g_size.height()/3)/g_worldsize.height()) * g_windowsize.height());
    }
    g_pixmap.resetTransform();
    g_pixmap.setPos(mappedPoint);
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}

void Barrier::collide()
{
    emit emitScore(2);
}
