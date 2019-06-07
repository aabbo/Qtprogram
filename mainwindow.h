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
   void MalClicked();

public:
    explicit MainWindow(QWidget *parent = nullptr,YutModel* ymodel=nullptr,YutController* ctrl=nullptr);
    ~MainWindow();

    void afterClickYut(bool status);
    void endTurn(bool status = false);

    void enableCurrentBoardButtonLocation();
    void setEnableMalButton();

    void setButtonDisable(int index);
    void setButtonEnable(int index);
    void setMainBoardUpdate();

    void malHighlightCanclation();

    int getStackedWidgetIndex();
private:
    bool setYutImg(int yut);
    bool setYutResult(QQueue<int> result);

    void clearYutFrame();

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


private:
    Ui::MainWindow *ui;
    MainBoard* board;
    MainTeams* teams;
    YutController* yctrl;
    YutModel* ymodel;
    int yut;

    const QString ButtonStyle = "border-color:rgb(0,0,0); border-width:1.2px; border-style:solid;"
                                     "border-radius:25px;";
    const QString ButtonBorderHighlight = "border-color:rgb(0,0,0); border-width:3.5px; border-style:solid;"
                                          "border-radius:25px;";
    const QString HighlightStyle = "image : url(:/img/highlight.png);";
    const QString initStyle = "";
};

#endif // MAINWINDOW_H
