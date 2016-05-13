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
#include <QPushButton>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <barrier.h>
#include <mycontactlistener.h>
#include <myscoreshow.h>
#include <enemy.h>
#include <speedbird.h>
#include <tribird.h>
#include <cstdlib>

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
    bool eventFilter(QObject *, QEvent *event);
    // For statics objects
    void setCatapult();
    QGraphicsPixmapItem *bucket;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    QPoint mouse_start, bird_start, line_end;

signals:
    void quitGame();

private slots:
    void receive(int num);
    void tick();
    void reset();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    Bird *birdie;
    Enemy *pig;
    QTimer timer;
    int mouseEventMode;
    // For score board
    MyScoreShow *Digits;
    MyScoreShow *Tens;
    MyScoreShow *Hundreds;
    int totalScore;
    // For Bird count
    MyScoreShow *bird_count;
    int birdcount;
    // Reset Button
    QPushButton *resetBtn, *startBtn;
    QGraphicsPixmapItem *endGame;
    // QList to maintain the shooted item
    QList<Bird*> list;

    bool started;
};

#endif // MAINWINDOW_H
