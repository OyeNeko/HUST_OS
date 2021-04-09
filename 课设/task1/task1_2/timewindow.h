#ifndef TIMEWINDOW_H
#define TIMEWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QMainWindow>
#include <QObject>
#include <QProcess>
#include <QDebug>

namespace Ui {
class TimeWindow;
}

class TimeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TimeWindow(QWidget *parent = nullptr);
    ~TimeWindow();

private:
    Ui::TimeWindow *ui;

public slots:
    void timerUpdate(void);

};

#endif // TIMEWINDOW_H
