#include "land.h"

Land::Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setPos(0,g_windowsize.height()-g_pixmap.boundingRect().height());
    scene->addItem(&g_pixmap);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    b2FixtureDef fixtureDef;
    fixtureDef.friction = 0.8f;
    fixtureDef.shape = &bodyBox;
    g_body->CreateFixture(&fixtureDef);   
}
