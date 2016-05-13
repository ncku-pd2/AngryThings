#include "land.h"

Land::Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);
    scene->addItem(&g_pixmap);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);
    b2FixtureDef fixtureDef;
    fixtureDef.friction = 0.8f;
    fixtureDef.shape = &bodyBox;
    g_body->CreateFixture(&fixtureDef);
    paint();
}
