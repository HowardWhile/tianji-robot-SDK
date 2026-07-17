#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "FXType.h"
#include "L1Robot.h"
#include <QMessageBox>
#include <atomic>
#include <QTextStream>
#include <QTimer>
#include <QCoreApplication>

#ifdef _WIN32
#define SLEEP_MS(ms) Sleep(ms)
#else
#define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

typedef struct
{
    double jointpos[7];
    double startcp[4][4];
    double up_jointpos[7];
    double up_xyzabc[6];
    double up_targetcp[4][4];
    double down_jointpos[7];
    double down_xyzabc[6];
    double down_targetcp[4][4];
} popos;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    

private slots: 
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    DWORD WINAPI TrajRun(LPVOID pParam);

    DWORD WINAPI TrajRun2(LPVOID pParam);

private:
    Ui::MainWindow *ui;
    popos left_pos[12];
    popos right_pos[13];
    int song_num;
    bool sing_flag;
    QTimer *m_Timer;

};

#endif // MAINWINDOW_H
