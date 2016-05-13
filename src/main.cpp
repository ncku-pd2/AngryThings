#include "maindialog.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    QDesktopWidget wid;
    MainDialog w;
    w.setGeometry(wid.screen()->width()/2 - w.width()/2 , wid.screen()->width()/2 - w.height()/2 , w.width(),w.height());
    w.show();

    return a.exec();
}
