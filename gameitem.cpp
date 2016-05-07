#include "gameitem.h"

GameItem::GameItem(b2World *world):
    g_body(NULL),g_world(world)
{
}

GameItem::~GameItem()
{
    g_world->DestroyBody(g_body);
}

QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

void GameItem::collide()
{

}

void GameItem::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    QPointF mappedPoint;
    mappedPoint.setX(((pos.x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f - (pos.y+g_size.height()/4)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.resetTransform();
    g_pixmap.setPos(mappedPoint);
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}

QPointF GameItem::posb2Toqt(float x, float y)
{
    return QPointF(x*g_windowsize.width()/g_worldsize.width(), (1.0f - y/g_worldsize.height()) * g_windowsize.height());
}

b2Vec2 GameItem::posqtTob2(float x, float y)
{
    return b2Vec2(x*g_worldsize.width()/g_windowsize.width(), (1.0f - y/g_windowsize.height()) * g_worldsize.height());
}

