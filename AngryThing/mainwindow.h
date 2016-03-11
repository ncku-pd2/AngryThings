#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    /* Variables */
    QGraphicsScene *scene;
    int screenWidth;
    int screenHeight;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
