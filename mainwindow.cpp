#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QMovie *movie = new QMovie("://img/endless.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setGeometry(200,150,180,100);
    processLabel->setVisible(true);
    processLabel->setMovie(movie);
    ui->hLayout_gif->addWidget(processLabel);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMenuAndActions()
{

}

