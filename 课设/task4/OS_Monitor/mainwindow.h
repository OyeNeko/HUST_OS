#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QListWidgetItem>
#include <QDateTime>
#include <QPainter>
#include <QStringList>

#include <unistd.h>
#include <sys/sysinfo.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<float> ylist;
    QList<float> ylistM;

public slots:
    void show_host_name();
    void show_proc_info();

    void show_mem_info();
    void Add_mem_Point();
    void Update_Mem_Line();



    void show_cpu_info();
    void Add_CPU_Point();
    void Update_CPU_Line();

    void update_current_time();



public:
    double cpu_usage;
    double mem_usage;
    double cpu_total=0;
    double cpu_used=0;
    QString proc_pid;

private slots:
    void on_tabWidget_currentChanged(int index);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_listWidget_process_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
