#include "pixmapitem.h"

PixmapItem::PixmapItem(QPixmap pixmap, QPointF screenSize, QPointF location, qreal zValue):
	gameItem(screenSize.x(),screenSize.y()),
	location(location)
{
	//status = 1;
	setPixmap(pixmap);
	setPos(location);
	setZValue(zValue);
}
