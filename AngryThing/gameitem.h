#ifndef GAMEITEM_H
#define GAMEITEM_H
#include <QGraphicsPixmapItem>

class gameItem : public QGraphicsPixmapItem
{
public:
    gameItem();
    int local_x;
    int local_y;
};

#endif // GAMEITEM_H
