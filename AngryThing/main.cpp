#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow w(QDesktopWidget().screen()->width()-200, QDesktopWidget().screen()->height()-200);
    w.show();
    return a.exec();
}
