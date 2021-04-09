/********************************************************************************
** Form generated from reading UI file 'cyclewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYCLEWINDOW_H
#define UI_CYCLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CycleWindow
{
public:
    QLabel *label;

    void setupUi(QWidget *CycleWindow)
    {
        if (CycleWindow->objectName().isEmpty())
            CycleWindow->setObjectName(QString::fromUtf8("CycleWindow"));
        CycleWindow->resize(400, 300);
        label = new QLabel(CycleWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 120, 400, 30));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        retranslateUi(CycleWindow);

        QMetaObject::connectSlotsByName(CycleWindow);
    } // setupUi

    void retranslateUi(QWidget *CycleWindow)
    {
        CycleWindow->setWindowTitle(QCoreApplication::translate("CycleWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("CycleWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CycleWindow: public Ui_CycleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYCLEWINDOW_H
