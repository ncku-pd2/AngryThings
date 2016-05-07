#ifndef MYSCORESHOW_H
#define MYSCORESHOW_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class MyScoreShow : public QGraphicsPixmapItem
{
public:
    MyScoreShow();
    void showResult(int num0_9);
};

#endif // MYSCORESHOW_H
