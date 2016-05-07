#include "mycontactlistener.h"

MyContactListener::MyContactListener()
{

}

void MyContactListener::BeginContact(b2Contact *contect)
{
    void* bodyUserData = contect->GetFixtureA()->GetBody()->GetUserData();
    if(bodyUserData)
    {
        static_cast<GameItem*>( bodyUserData )->collide();
    }
    //cout << "Begin " << endl;
}

void MyContactListener::EndContact(b2Contact *contect)
{
    // For the texture leave the other texture

    //cout << "End " << endl;
}

