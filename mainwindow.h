#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *obj, QEvent *event);
    // For statics objects
    void setCatapult();
    QGraphicsPixmapItem *bucket;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int line_end_x;
    int line_end_y;
    float bird_start_x;
    float bird_start_y;
    int mouse_start_x;
    int mouse_start_y;
private slots:
    void tick();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    Bird *birdie;
    QTimer timer;
    int mouseEventMode;
};

#endif // MAINWINDOW_H
