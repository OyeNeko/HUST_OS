#ifndef CYCLEWINDOW_H
#define CYCLEWINDOW_H

#include <QWidget>
#include <QTimer>
#include<QString>
namespace Ui {
class CycleWindow;
}

class CycleWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CycleWindow(QWidget *parent = nullptr);
    ~CycleWindow();

private:
    Ui::CycleWindow *ui;
    int sum;
public slots:
    void CycleUpdate(void);

};

#endif // CYCLEWINDOW_H
