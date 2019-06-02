#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QResizeEvent>
#include "mainboard.h"
#include "setupdialog.h"
#include "resultdialog.h"
class YutController;
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr,YutController* ctrl=nullptr);
    bool setup_bool();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainBoard* board;
    YutController* yctrl;

protected:
    SetupDialog *setupDig;
    ResultDialog *resultDig;
    //void resizeEvent(QResizeEvent* event);
};

#endif // MAINWINDOW_H
