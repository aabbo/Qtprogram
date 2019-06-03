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

private:
    bool setYutImg(int yut);
    bool setYutResult(QQueue<int> result);
    Ui::MainWindow *ui;
    MainBoard* board;
    MainTeams* teams;
    YutController* yctrl;
    YutModel* ymodel;

private slots:
    void on_RandomButton_clicked();
    void on_SelectButton_clicked();
};

#endif // MAINWINDOW_H
