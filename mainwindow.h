#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QResizeEvent>
#include <QObject>

#include "mainboard.h"
#include "setupdialog.h"
#include "resultdialog.h"

class YutController;
#include "yutmodel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
   void clicked(QPushButton* btn);

public:
    explicit MainWindow(QWidget *parent = nullptr,YutModel* ymodel=nullptr,YutController* ctrl=nullptr);
    bool setup_bool();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainBoard* board;
    YutController* yctrl;
    YutModel* ymodel;

protected:
    SetupDialog *setupDig;
    ResultDialog *resultDig;
    //void resizeEvent(QResizeEvent* event);
private slots:
    void on_RandomButton_clicked();
    void on_SelectButton_clicked();
};

#endif // MAINWINDOW_H
