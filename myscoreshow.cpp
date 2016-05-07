#include "myscoreshow.h"

MyScoreShow::MyScoreShow()
{

}

void MyScoreShow::showResult(int num0_9)
{
    QString pre(":/number/");
    QString num = QString::number(num0_9);
    QString post(".png");
    QString total = pre+num+post;
    QPixmap a(total);
    this->setPixmap(a.scaled(a.width()/2,a.height()/2,Qt::KeepAspectRatio));
}

