#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->move(1100,200);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ClickButton()));
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::ClickButton()
{
    str=ui->textEdit->toPlainText();
    QFile fp("save.txt");
    if(!fp.open(QIODevice::WriteOnly)){
        return;
    }

    QByteArray  s = str.toUtf8();
    fp.write(s,s.length());
    fp.close();
    return ;
}

