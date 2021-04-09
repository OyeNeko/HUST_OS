#include "mainwindow.h"

#include <QApplication>

#include"timewindow.h"
#include"cyclewindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int pid;
    if((pid = fork()) == 0){
        QApplication a(argc,argv);
        TimeWindow w;
        w.setWindowTitle("Timer Monitor");
        w.show();
        a.exec();
        exit(0);
    }
    if((pid = fork()) == 0){
        QApplication a(argc,argv);
        CycleWindow w;
        w.setWindowTitle("Counter Monitor");
        w.show();
        a.exec();
        exit(0);
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Saver Monitor");
    w.show();

    return a.exec();
}

