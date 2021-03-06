#ifndef YUTCONTROLLER_H
#define YUTCONTROLLER_H

#include <QObject>
#include <QApplication>
#include "mainwindow.h"
#include "resultdialog.h"
#include "setupdialog.h"
#include "yutmodel.h"
#include "boardsetthread.h"

class YutController : public QObject
{
    Q_OBJECT
public:
    explicit YutController(QObject *parent = nullptr);
    bool gamestart;
signals:
    void updateQueue(bool isEmpty);
    void malClicked();
    void boardButtonClicked();
    void threadInit();
    void threadRestart();

public slots:
    void malSetEnd();
    void updateEnableMal();

public:
    //mainwindow view
    void clickedBoardBtn(int num);
    void clickedYut(int yut = -1);
    void clickedRemainedMal();
    void setStart();
    void endTurn();
    void resetGame();

public:
    MainWindow * mw;
    SetupDialog * sd;
    ResultDialog * rd;
    YutModel* ymodel;
    BoardSetThread* thread;
    bool isThreadExist;
    bool isRestart;
public:
    bool boardSet = false;
};

#endif // YUTCONTROLLER_H
