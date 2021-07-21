#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "sourceApp/threadModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int shm;
    void *addr;
    Ui::MainWindow *ui;
private slots:
    void slotTimerAlarm();
    void receivingData();


private:

    QTimer *timer;
    ThreadModel *model;

    //-----Print
    void  Print_manager       ();
    void  Print_aircondition  ();
    void  Print_antifire      ();
    void  Print_antiicing     ();
    void  Print_brakes        ();
    void  Print_cabinlighting ();
    void  Print_emergencyalarm();
    void  Print_hydro         ();
    void  Print_landinggea    ();
    void  Print_pneumatic     ();
    void  Print_powerdc       ();
    void  Print_presure       ();
    void  Print_wingsmech     ();

};
#endif // MAINWINDOW_H
