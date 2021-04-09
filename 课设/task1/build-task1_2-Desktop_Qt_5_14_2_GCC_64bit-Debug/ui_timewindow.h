/********************************************************************************
** Form generated from reading UI file 'timewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEWINDOW_H
#define UI_TIMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeWindow
{
public:
    QLabel *Time;
    QLabel *timetext;

    void setupUi(QWidget *TimeWindow)
    {
        if (TimeWindow->objectName().isEmpty())
            TimeWindow->setObjectName(QString::fromUtf8("TimeWindow"));
        TimeWindow->resize(400, 300);
        Time = new QLabel(TimeWindow);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(80, 190, 300, 71));
        QFont font;
        font.setPointSize(20);
        Time->setFont(font);
        timetext = new QLabel(TimeWindow);
        timetext->setObjectName(QString::fromUtf8("timetext"));
        timetext->setGeometry(QRect(160, 40, 133, 27));
        QFont font1;
        font1.setPointSize(25);
        timetext->setFont(font1);

        retranslateUi(TimeWindow);

        QMetaObject::connectSlotsByName(TimeWindow);
    } // setupUi

    void retranslateUi(QWidget *TimeWindow)
    {
        TimeWindow->setWindowTitle(QCoreApplication::translate("TimeWindow", "Form", nullptr));
        Time->setText(QCoreApplication::translate("TimeWindow", "Time", nullptr));
        timetext->setText(QCoreApplication::translate("TimeWindow", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeWindow: public Ui_TimeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEWINDOW_H
