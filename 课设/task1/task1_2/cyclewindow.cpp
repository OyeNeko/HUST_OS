#include "cyclewindow.h"
#include "ui_cyclewindow.h"

CycleWindow::CycleWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CycleWindow),sum(0)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->move(300,200);
    QTimer*timer = new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(CycleUpdate()));
    timer->start(1000);
}

CycleWindow::~CycleWindow()
{
    delete ui;
}

void CycleWindow::CycleUpdate()
{
    sum=(sum+1)%10;
    ui->label->setText(QString::number(sum));
}
