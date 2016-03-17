#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gameitem.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int width , int height, QWidget *parent = 0);
    ~MainWindow();
    /* Functions */
    void settingBackground(int bgw,int bgh);
    void settingInitObj();
    /* Variables */
    QGraphicsScene *scene;
    int screenWidth;
    int screenHeight;
    /* Game obj */
    gameItem *bird1;
    QString bird1_path;
    /* FIXME : need to change catapult class */
    gameItem *catapult_upper;
    QString cata_up_path;
    gameItem *catapult_lower;
    QString cata_lo_path;
    /* FIXME : need to reset the z-value for all items */
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
