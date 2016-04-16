#include "pixmapitem.h"

PixmapItem::PixmapItem(QPixmap pixmap, QPointF screenSize, QPointF location, qreal zValue):
	gameItem(screenSize.x(),screenSize.y()),
	location(location)
{
    // For an ignore collision item
    status = 0;
	setPixmap(pixmap);
	setPos(location);
	setZValue(zValue);
}
