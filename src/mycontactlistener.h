#ifndef MYCONTACTLISTENER_H
#define MYCONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include <gameitem.h>
#include <iostream>

using namespace std;

class MyContactListener : public b2ContactListener
{
public:
    MyContactListener();
    void BeginContact(b2Contact *contect);
    void EndContact(b2Contact *contect);
};

#endif // MYCONTACTLISTENER_H
