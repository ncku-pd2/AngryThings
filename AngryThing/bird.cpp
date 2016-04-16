#include "bird.h"

bird::bird(qreal size_x, qreal size_y) : gameItem(size_x,size_y)
{
	grav_accel = 0.2;
	x_accel = 0;
	y_accel = 0;
	speed_x = 0;
	speed_y = 0;
	allowPhysic = false;

    // define status
    status = 1;
}

void bird::advance(int)
{
	if(allowPhysic){
		speed_y += (0.1)*grav_accel;
		x_accel = -0.01;

		if(speed_x > 0)
			speed_x += x_accel;
		else if(speed_x < 0)
			speed_x -= x_accel;

		this->setPos(this->pos().x()+speed_x,this->pos().y()+speed_y);

		checkBoundary();
	}
}

bool bird::checkBoundary()
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
		if(obj_x <= leftBound)
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
			if(this->speed_x > 0)
				this->speed_x -= 0.01;
			else if(this->speed_x < 0)
				this->speed_x += 0.5;
			this->speed_y = 0;
		}
		else if(obj_x > rightBound)
		{
			this->setPos(rightBound , lowerBound);
			this->speed_x = 0;
			this->speed_y = 0;
			//this->status = 1;
		}
	}
}
