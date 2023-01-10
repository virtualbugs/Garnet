#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setMenuAndActions();

private:
    Ui::MainWindow *ui;

    QSystemTrayIcon *trayIcon;

    QMenu *trayIconMenu;
    QMenu *subMenu_Speaker;
    QMenu *subMenu_Microphone;
    QMenu *subMenu_Cam;
    QAction *hideAction;
    QAction *showAction;
    QAction *exitAction;

    QAction *speakerAction_on;
    QAction *speakerAction_off;

    QAction *microphoneAction_on;
    QAction *microphoneAction_off;

    QAction *camAction_on;
    QAction *camAction_off;


};
#endif // MAINWINDOW_H
