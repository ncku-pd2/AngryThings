#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget wid;
    MainWindow w;
    w.setGeometry(wid.screen()->width()/2 - w.width()/2 , wid.screen()->width()/2 - w.height()/2 , w.width(),w.height());
    w.show();

    return a.exec();
}
