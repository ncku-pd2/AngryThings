#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int screenWidth = QDesktopWidget().screen()->width();
    int screenHeight = QDesktopWidget().screen()->height();
    int width = screenWidth - 300;
    int height = screenHeight - 150;
    MainWindow w(width -200, height-100);
    w.setFixedSize(width , height);
    w.settingBackground(width-200,height);
    w.setGeometry((screenWidth/2)-(width/2) , (screenHeight/2) - (height/2) , width , height);
    w.show();
    return a.exec();
}
