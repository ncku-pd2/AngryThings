#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gameitem.h>
#include <scene.h>
#include <QPainter>
#include <QMainWindow>
#include <QGraphicsScene>
#include <iostream>
#include <QTimer>

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
    Scene* scene;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
