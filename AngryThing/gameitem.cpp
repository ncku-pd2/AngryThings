#include "gameitem.h"
#include <iostream>

using namespace std;

gameItem::gameItem(qreal size_x, qreal size_y)
{
    status = 0;
    grav_accel = 0.5;
    x_accel = 0;
    y_accel = 0;
    speed_x = 0;
    speed_y = 0;

    screenSize_x = size_x;
    screenSize_y = size_y;

    upperBound = 0;
    leftBound = -75;
    rightBound = size_x+50;
    lowerBound = size_y-40;
}

void gameItem::advance(int phase)
{
    /*
    if(phase == 0)
        cout<< "phase = 0" << endl;
    else
        cout<< "phase = " << phase << endl;
    */
    if(status == 1)
    {
        /* Don't need to consider physic */
    }
    else if(status == 0){
        /* Calculate the physic status */
        speed_y += (0.5)*grav_accel;
        x_accel = -0.1;

        if(speed_x > 0)
            speed_x += x_accel;
        else
            speed_x = 0;

        this->setPos(this->pos().x()+speed_x,this->pos().y()+speed_y);
    }
    cout<< this->pos().x() << " ; " << this->pos().y() << endl;
    cout<< "speed is "<< this->speed_y << endl;
    checkBoundary();
}

void gameItem::checkBoundary()
{
    qreal obj_x = this->pos().x();
    qreal obj_y = this->pos().y();
    /* upper */
    if(obj_y <= upperBound)
    {
        if(obj_x <= leftBound)
        {
            this->setPos(leftBound,upperBound);
            this->speed_x = 0;
            this->speed_y = 0;
        }
        else if(obj_x > leftBound && obj_x <= rightBound)
        {
            this->setPos(obj_x , upperBound);
            this->speed_y = 0;
        }
        else if(obj_x > rightBound)
        {
            this->setPos(rightBound , upperBound);
            this->speed_x = 0;
        }
    }
    else if(obj_y > upperBound && obj_y <= lowerBound)
    {
        if(obj_x < leftBound)
        {
            this->setPos(leftBound,obj_y);
            this->speed_x = 0;
        }
        else if(obj_x > leftBound && obj_x <= rightBound)
        {
            this->setPos(obj_x , obj_y);
        }
        else if(obj_x > rightBound)
        {
            this->setPos(rightBound , obj_y);
            this->speed_x = 0;
        }
    }
    else if(obj_y > lowerBound)
    {
        if(obj_x <= leftBound)
        {
            this->setPos(leftBound,lowerBound);
            this->speed_x = 0;
            this->speed_y = 0;
        }
        else if(obj_x > leftBound && obj_x <= rightBound)
        {
            this->setPos(obj_x , lowerBound);
            this->speed_y = 0;
        }
        else if(obj_x > rightBound)
        {
            this->setPos(rightBound , lowerBound);
            this->speed_x = 0;
            this->speed_y = 0;
            this->status = 1;
        }
    }


}

