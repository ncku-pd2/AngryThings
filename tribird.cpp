#include "tribird.h"

TriBird::TriBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene, bool mainB)
    :Bird(x, y, radius, timer, pixmap, world, scene),timer(timer),scene(scene),world(world),
      radius(radius),pixmap(pixmap),mainTri(mainB),mainClicked(false)
{
    if(!mainTri){
        // Create Body
        b2BodyDef bodydef;
        bodydef.type = b2_dynamicBody;
        bodydef.bullet = true;
        bodydef.position.Set(x,y);
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
}

void TriBird::clearBuffer()
{
    for(int i=0; i<triList.size(); ++i){
        delete triList.at(i);
    }
    triList.clear();
}

QList<TriBird *> TriBird::triList = QList<TriBird *>();

void TriBird::click()
{
    if(mainTri && !mainClicked){
        TriBird *new1;
        b2Vec2 pos = g_body->GetPosition();
        b2Vec2 vel = g_body->GetLinearVelocity();
        new1 = new TriBird(pos.x,pos.y,radius,timer,pixmap,world,scene,false);
        new1->setLinearVelocity(b2Vec2(vel.x,vel.y*1.5));
        triList.push_back(new1);
        mainClicked = true;
    }
}
