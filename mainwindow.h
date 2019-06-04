#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QLabel>

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
   void clicked(QPushButton* btn);
   void clickedBeforeMal();

public:
    explicit MainWindow(QWidget *parent = nullptr,YutModel* ymodel=nullptr,YutController* ctrl=nullptr);
    ~MainWindow();
    void afterClickYut(bool status);
    void clearYutResult();

private:
    bool setYutImg(int yut = -2);
    bool setYutResult(QQueue<int> result);
    void disableButton(int index);
    void enableButton(int index);
    Ui::MainWindow *ui;
    MainBoard* board;
    MainTeams* teams;
    YutController* yctrl;
    YutModel* ymodel;
    int yut;

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
