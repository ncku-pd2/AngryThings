#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(qreal width , qreal height , QWidget *parent = 0);
    ~MainWindow();

    QGraphicsScene *scene;

    qreal x_sceneSize;
    qreal y_sceneSize;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
