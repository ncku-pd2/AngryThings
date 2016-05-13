#include "bird.h"

Bird::Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world),
    x_pos(x), y_pos(y), radius(radius), world(world), timer(timer),grounded(false)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSizeF(radius*2,radius*2);
    g_pixmap.setPos(posb2Toqt(x,y));
    scene->addItem(&g_pixmap);
}

void Bird::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    if(((pos.y <= (groundHeight+g_size.height()/1.5f))||(pos.y < -10)||(pos.x < -10) || (pos.x > g_worldsize.width()))&&(!grounded)){
        grounded = true;
    }
    QPointF mappedPoint;
    mappedPoint.setX(((pos.x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f - (pos.y+g_size.height()*1.5)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.resetTransform();
    g_pixmap.setPos(mappedPoint);
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}

void Bird::collide()
{
    emit emitScore(1);
    if(g_body->GetGravityScale() < 1.0f){
        g_body->SetGravityScale(1.0f);
        g_body->SetLinearVelocity(b2Vec2(g_body->GetLinearVelocity().x * 0.5f,g_body->GetLinearVelocity().y * 0.5f));
    }
}

void Bird::click()
{

}

void Bird::startShoot()
{
    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x_pos,y_pos);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(5);
    g_body->CreateFixture(&fixturedef);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
}

void Bird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}
