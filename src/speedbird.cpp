#include "speedbird.h"

SpeedBird::SpeedBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene)
    :Bird(x, y, radius, timer, pixmap, world, scene)
{

}

void SpeedBird::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    if(((pos.y <= (groundHeight+g_size.height()/1.5f))||(pos.y < -10)||(pos.x < -10) || (pos.x > g_worldsize.width()))&&(!grounded)){
        grounded = true;
        if(g_body->GetGravityScale() < 1.0f){
            g_body->SetGravityScale(1.0f);
            g_body->SetLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x * 0.25f,g_body->GetLinearVelocity().y * 0.25f));
        }
    }
    QPointF mappedPoint;
    mappedPoint.setX(((pos.x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f - (pos.y+g_size.height()*1.5)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.resetTransform();
    g_pixmap.setPos(mappedPoint);
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}

void SpeedBird::click()
{
    g_body->SetGravityScale(0.0f);
    g_body->SetLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x * 4.0f,g_body->GetLinearVelocity().y * 4.0f));
}
