#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QResizeEvent>
#include "mainboard.h"
#include "setupdialog.h"
#include "resultdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    bool setup_bool();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainBoard* board;

protected:
    SetupDialog *setupDig;
    ResultDialog *resultDig;
    //void resizeEvent(QResizeEvent* event);
};

#endif // MAINWINDOW_H
