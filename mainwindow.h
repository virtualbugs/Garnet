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
    QAction *hideAction;
    QAction *showAction;
    QAction *exitAction;
    QAction *speakerAction;
    QAction *microphoneAction;
    QAction *camAction;

};
#endif // MAINWINDOW_H
