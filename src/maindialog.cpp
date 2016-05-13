#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    mainwindow = new MainWindow;
    ui->gridLayout->addWidget(mainwindow,0,0);
    mainwindow->show();
    connect(mainwindow,SIGNAL(quitGame()),this,SLOT(backMenu()));
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::startGame()
{
}

void MainDialog::backMenu()
{
    qDebug()<< "Signaled";
}

void MainDialog::closeEvent(QCloseEvent *)
{
    qDebug()<< "Closed";
}
