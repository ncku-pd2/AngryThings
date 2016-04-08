#ifndef BIRD_H
#define BIRD_H

#include "gameitem.h"

class bird : public gameItem
{

public:
	explicit bird(qreal size_x , qreal size_y);
	void advance(int);
	bool checkBoundary();

	/* Physical variable */
	qreal speed_x;
	qreal speed_y;
	qreal grav_accel; // Gravity
	qreal x_accel; // x-axis acceleration
	qreal y_accel; // y-axis acceleration

	bool allowPhysic;
};

#endif // BIRD_H
