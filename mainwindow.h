#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QEvent>

#include "ui_mainwindow.h"
#include "selectyutdialog.h"
#include "mainboard.h"
#include "mainteams.h"
#include "yutmodel.h"

class YutController;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
   void clickedBeforeMal();

public:
    explicit MainWindow(QWidget *parent = nullptr,YutModel* ymodel=nullptr,YutController* ctrl=nullptr);
    ~MainWindow();
    void afterClickYut(bool status);

private:
    bool setYutImg(int yut);
    bool setYutResult(QQueue<int> result);
    Ui::MainWindow *ui;
    MainBoard* board;
    MainTeams* teams;
    YutController* yctrl;
    YutModel* ymodel;
    int yut;

protected:
    bool eventFilter(QObject* object, QEvent* event);
private slots:
    void on_RandomButton_clicked();
    void on_SelectButton_clicked();
    void on_SelectThrow_clicked();
    void on_BackPage_clicked();
    void on_BackDo_clicked();
    void on_Do_clicked();
    void on_Gae_clicked();
    void on_Gul_clicked();
    void on_Yut_clicked();
    void on_Mo_clicked();
};

#endif // MAINWINDOW_H
