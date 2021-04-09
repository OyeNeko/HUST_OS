/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Main;
    QLabel *host_name;
    QLabel *start_time;
    QLabel *run_time;
    QLabel *sys_version_2;
    QLabel *CPU_type;
    QLabel *start_time_2;
    QLabel *host_name_2;
    QLabel *run_time_2;
    QLabel *sys_version;
    QLabel *CPU_name;
    QWidget *Memory;
    QLabel *label_6;
    QProgressBar *progressBar_mem;
    QLabel *mem_line;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *CPU;
    QLabel *cpu_rate_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *cpu_line;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *cpu_rate_3;
    QProgressBar *progressBar_cpu;
    QWidget *prograss;
    QListWidget *listWidget_process;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *now_time;
    QLabel *now_time_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(985, 568);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(70, 30, 841, 461));
        Main = new QWidget();
        Main->setObjectName(QString::fromUtf8("Main"));
        host_name = new QLabel(Main);
        host_name->setObjectName(QString::fromUtf8("host_name"));
        host_name->setGeometry(QRect(290, 20, 250, 60));
        QFont font;
        font.setPointSize(15);
        host_name->setFont(font);
        start_time = new QLabel(Main);
        start_time->setObjectName(QString::fromUtf8("start_time"));
        start_time->setGeometry(QRect(290, 120, 250, 60));
        start_time->setFont(font);
        run_time = new QLabel(Main);
        run_time->setObjectName(QString::fromUtf8("run_time"));
        run_time->setGeometry(QRect(290, 220, 250, 60));
        run_time->setFont(font);
        run_time->setFrameShape(QFrame::NoFrame);
        sys_version_2 = new QLabel(Main);
        sys_version_2->setObjectName(QString::fromUtf8("sys_version_2"));
        sys_version_2->setGeometry(QRect(450, 20, 250, 60));
        sys_version_2->setFont(font);
        CPU_type = new QLabel(Main);
        CPU_type->setObjectName(QString::fromUtf8("CPU_type"));
        CPU_type->setGeometry(QRect(130, 320, 250, 60));
        CPU_type->setFont(font);
        start_time_2 = new QLabel(Main);
        start_time_2->setObjectName(QString::fromUtf8("start_time_2"));
        start_time_2->setGeometry(QRect(130, 120, 250, 60));
        start_time_2->setFont(font);
        host_name_2 = new QLabel(Main);
        host_name_2->setObjectName(QString::fromUtf8("host_name_2"));
        host_name_2->setGeometry(QRect(130, 20, 250, 60));
        host_name_2->setFont(font);
        run_time_2 = new QLabel(Main);
        run_time_2->setObjectName(QString::fromUtf8("run_time_2"));
        run_time_2->setGeometry(QRect(130, 220, 250, 60));
        run_time_2->setFont(font);
        run_time_2->setFrameShape(QFrame::NoFrame);
        sys_version = new QLabel(Main);
        sys_version->setObjectName(QString::fromUtf8("sys_version"));
        sys_version->setGeometry(QRect(610, 20, 250, 60));
        sys_version->setFont(font);
        CPU_name = new QLabel(Main);
        CPU_name->setObjectName(QString::fromUtf8("CPU_name"));
        CPU_name->setGeometry(QRect(290, 320, 411, 78));
        CPU_name->setFont(font);
        tabWidget->addTab(Main, QString());
        Memory = new QWidget();
        Memory->setObjectName(QString::fromUtf8("Memory"));
        label_6 = new QLabel(Memory);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 10, 180, 70));
        label_6->setFont(font);
        progressBar_mem = new QProgressBar(Memory);
        progressBar_mem->setObjectName(QString::fromUtf8("progressBar_mem"));
        progressBar_mem->setGeometry(QRect(150, 20, 601, 41));
        progressBar_mem->setValue(24);
        mem_line = new QLabel(Memory);
        mem_line->setObjectName(QString::fromUtf8("mem_line"));
        mem_line->setGeometry(QRect(90, 100, 720, 300));
        label_7 = new QLabel(Memory);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 92, 67, 17));
        QFont font1;
        font1.setPointSize(11);
        label_7->setFont(font1);
        label_8 = new QLabel(Memory);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 240, 67, 17));
        label_8->setFont(font1);
        label_9 = new QLabel(Memory);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 390, 67, 17));
        label_9->setFont(font1);
        tabWidget->addTab(Memory, QString());
        CPU = new QWidget();
        CPU->setObjectName(QString::fromUtf8("CPU"));
        cpu_rate_2 = new QLabel(CPU);
        cpu_rate_2->setObjectName(QString::fromUtf8("cpu_rate_2"));
        cpu_rate_2->setGeometry(QRect(30, 0, 180, 70));
        cpu_rate_2->setFont(font);
        label = new QLabel(CPU);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 92, 67, 17));
        label_2 = new QLabel(CPU);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 162, 67, 17));
        cpu_line = new QLabel(CPU);
        cpu_line->setObjectName(QString::fromUtf8("cpu_line"));
        cpu_line->setGeometry(QRect(90, 100, 720, 300));
        label_3 = new QLabel(CPU);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 240, 67, 17));
        label_4 = new QLabel(CPU);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 310, 67, 17));
        label_5 = new QLabel(CPU);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 390, 67, 17));
        cpu_rate_3 = new QLabel(CPU);
        cpu_rate_3->setObjectName(QString::fromUtf8("cpu_rate_3"));
        cpu_rate_3->setGeometry(QRect(290, 0, 180, 70));
        cpu_rate_3->setFont(font);
        progressBar_cpu = new QProgressBar(CPU);
        progressBar_cpu->setObjectName(QString::fromUtf8("progressBar_cpu"));
        progressBar_cpu->setGeometry(QRect(150, 20, 541, 41));
        progressBar_cpu->setValue(24);
        tabWidget->addTab(CPU, QString());
        prograss = new QWidget();
        prograss->setObjectName(QString::fromUtf8("prograss"));
        listWidget_process = new QListWidget(prograss);
        listWidget_process->setObjectName(QString::fromUtf8("listWidget_process"));
        listWidget_process->setGeometry(QRect(30, 20, 781, 351));
        listWidget_process->setFocusPolicy(Qt::StrongFocus);
        pushButton_2 = new QPushButton(prograss);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 390, 89, 25));
        pushButton_3 = new QPushButton(prograss);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(500, 390, 89, 25));
        tabWidget->addTab(prograss, QString());
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(760, 500, 91, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Umpush"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton->setFont(font2);
        pushButton->setIconSize(QSize(24, 16));
        now_time = new QLabel(centralwidget);
        now_time->setObjectName(QString::fromUtf8("now_time"));
        now_time->setGeometry(QRect(300, 510, 241, 41));
        QFont font3;
        font3.setPointSize(20);
        now_time->setFont(font3);
        now_time_2 = new QLabel(centralwidget);
        now_time_2->setObjectName(QString::fromUtf8("now_time_2"));
        now_time_2->setGeometry(QRect(140, 510, 241, 41));
        now_time_2->setFont(font3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        host_name->setText(QCoreApplication::translate("MainWindow", "\344\270\273\346\234\272\345\220\215", nullptr));
        start_time->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\346\227\266\351\227\264", nullptr));
        run_time->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        sys_version_2->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\211\210\346\234\254\345\217\267\357\274\232", nullptr));
        CPU_type->setText(QCoreApplication::translate("MainWindow", "CPU\345\236\213\345\217\267\357\274\232", nullptr));
        start_time_2->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\346\227\266\351\227\264\357\274\232", nullptr));
        host_name_2->setText(QCoreApplication::translate("MainWindow", "\344\270\273\346\234\272\345\220\215\357\274\232", nullptr));
        run_time_2->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214\346\227\266\351\227\264\357\274\232", nullptr));
        sys_version->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\211\210\346\234\254\345\217\267", nullptr));
        CPU_name->setText(QCoreApplication::translate("MainWindow", "CPU\345\236\213\345\217\267\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Main), QCoreApplication::translate("MainWindow", "\344\270\273\346\234\272\344\277\241\346\201\257", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\206\205\345\255\230\344\275\277\347\224\250\347\216\207", nullptr));
        mem_line->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "50%", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Memory), QCoreApplication::translate("MainWindow", "\345\206\205\345\255\230\350\265\204\346\272\220", nullptr));
        cpu_rate_2->setText(QCoreApplication::translate("MainWindow", "CPU\344\275\277\347\224\250\347\216\207\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "75%", nullptr));
        cpu_line->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "50%", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "25%", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        cpu_rate_3->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(CPU), QCoreApplication::translate("MainWindow", "CPU\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(prograss), QCoreApplication::translate("MainWindow", "\350\277\233\347\250\213\344\277\241\346\201\257", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\346\234\272", nullptr));
        now_time->setText(QCoreApplication::translate("MainWindow", "now_time", nullptr));
        now_time_2->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
