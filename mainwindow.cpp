#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMenuAndActions();
    setWindowTitle("|_|_Garnet_|_|");

    QMovie *movie = new QMovie("://img/endless.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setGeometry(200,150,180,100);
    processLabel->setVisible(true);
    processLabel->setMovie(movie);
    ui->hLayout_gif->addWidget(processLabel);
    movie->start();
    trayIcon->show();

    QIcon *icon = new QIcon("://img/tray_icon.png");
    trayIcon->setIcon(*icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMenuAndActions()
{
    trayIconMenu = new QMenu(this);
    subMenu_Speaker = new QMenu("Speaker", this);
    subMenu_Microphone = new QMenu("Microphone", this);
    subMenu_Cam = new QMenu("Cam", this);
    trayIconMenu->addMenu(subMenu_Speaker);
    trayIconMenu->addMenu(subMenu_Microphone);
    trayIconMenu->addMenu(subMenu_Cam);

    hideAction = new QAction("Hide");
    showAction = new QAction("Show");
    exitAction = new QAction("Exit");

    speakerAction_on = new QAction("On");
    speakerAction_off = new QAction("Off");

    microphoneAction_on = new QAction("On");
    microphoneAction_off = new QAction("Off");

    camAction_on = new QAction("On");
    camAction_off = new QAction("Off");

    subMenu_Speaker->addAction(speakerAction_on);
    subMenu_Speaker->addAction(speakerAction_off);
    subMenu_Microphone->addAction(microphoneAction_on);
    subMenu_Microphone->addAction(microphoneAction_off);
    subMenu_Cam->addAction(camAction_on);
    subMenu_Cam->addAction(camAction_off);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(hideAction);
    trayIconMenu->addAction(showAction);
    trayIconMenu->addAction(exitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

