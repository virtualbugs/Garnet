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

    connect(hideAction, SIGNAL(triggered()), this, SLOT(onHideAction()));
    connect(showAction, SIGNAL(triggered()), this, SLOT(onShowAction()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(onExitAction()));
    connect(speakerAction_on, SIGNAL(triggered()), this, SLOT(onSpeakerActionOn()));
    connect(speakerAction_off, SIGNAL(triggered()), this, SLOT(onSpeakerActionOff()));
    connect(microphoneAction_on, SIGNAL(triggered()), this, SLOT(onMicrophoneActionOn()));
    connect(microphoneAction_off, SIGNAL(triggered()), this, SLOT(onMicrophoneActionOff()));
    connect(camAction_on, SIGNAL(triggered()), this, SLOT(onCamActionOn()));
    connect(camAction_off, SIGNAL(triggered()), this, SLOT(onCamActionOff()));

    connect(ui->rb_speaker_on, SIGNAL(clicked(bool)), this, SLOT(onSpeakerActionOn()));
    connect(ui->rb_speaker_off, SIGNAL(clicked(bool)), this, SLOT(onSpeakerActionOff()));
    connect(ui->rb_microphone_on, SIGNAL(clicked(bool)), this, SLOT(onMicrophoneActionOn()));
    connect(ui->rb_microphone_off, SIGNAL(clicked(bool)), this, SLOT(onMicrophoneActionOff()));
    connect(ui->rb_cam_on, SIGNAL(clicked(bool)), this, SLOT(onCamActionOn()));
    connect(ui->rb_cam_off, SIGNAL(clicked(bool)), this, SLOT(onCamActionOff()));

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


void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    hide();
}

void MainWindow::onHideAction()
{
    hide();
}

void MainWindow::onShowAction()
{
    show();
}

void MainWindow::onExitAction()
{
    QApplication::quit();
}

void MainWindow::onSpeakerActionOn()
{
    QStringList command = QStringList() << "-c" << "pactl set-sink-volume 0 30%";
    QProcess process;
    process.start("/bin/bash", command);
    if (!process.waitForFinished()) {
        qDebug() << "fail on Speaker Action On";
        return;
    }
}

void MainWindow::onSpeakerActionOff()
{
    QStringList command = QStringList() << "-c" << "pactl set-sink-volume 0 0%";
    QProcess process;
    process.start("/bin/bash", command);
    if (!process.waitForFinished()) {
        qDebug() << "fail on Speaker Action Off";
    }
}

void MainWindow::onMicrophoneActionOn()
{
    QStringList command = QStringList() << "-c" << "amixer set Capture cap";
    QProcess process;
    process.start("/bin/bash", command);
    if (!process.waitForFinished()) {
        qDebug() << "fail on Microphone Action On";
    }
}

void MainWindow::onMicrophoneActionOff()
{
    QStringList command = QStringList() << "-c" << "amixer set Capture nocap";
    QProcess process;
    process.start("/bin/bash", command);
    if (!process.waitForFinished()) {
        qDebug() << "fail on Microphone Action Off";
    }
}

void MainWindow::onCamActionOn()
{
    QStringList command = QStringList() << "-c" << "modprobe uvcvideo";
    QProcess process;
    process.start("/bin/bash", command);
    if (!process.waitForFinished()) {
        qDebug() << "fail on Cam Action On";
    }
}

void MainWindow::onCamActionOff()
{
    QStringList command = QStringList() << "-c" << "modprobe -r uvcvideo";
    QProcess process;
    process.start("/bin/bash", command);
    if (!process.waitForFinished()) {
        qDebug() << "fail on Cam Action Off";
    }
}
