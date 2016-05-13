#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <mainwindow.h>

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private slots:
    void startGame();
    void backMenu();

private:
    Ui::MainDialog *ui;
    MainWindow *mainwindow;
    void closeEvent(QCloseEvent *);
};

#endif // MAINDIALOG_H
