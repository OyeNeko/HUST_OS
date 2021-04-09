#include "timewindow.h"
#include "ui_timewindow.h"
#include <QMessageBox>
TimeWindow::TimeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->move(700,200);
    QTimer*timer = new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
}

TimeWindow::~TimeWindow()
{
    delete ui;
}

void TimeWindow::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("hh:mm:ss dddd");
    ui->Time->setText(str);
}
