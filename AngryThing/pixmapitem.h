#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include <QPixmap>
#include "gameitem.h"

class PixmapItem : public gameItem
{
public:
	explicit PixmapItem(QPixmap pixmap, QPointF screenSize, QPointF location, qreal zValue = 0);

signals:

public slots:

private:
	QPointF location;
};

#endif // PIXMAPITEM_H
