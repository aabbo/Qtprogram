#ifndef YUTCONTROLLER_H
#define YUTCONTROLLER_H

#include <QObject>
#include <QApplication>
#include "mainwindow.h"
#include "yutmodel.h"

class YutController : public QObject
{
    Q_OBJECT
public:
    explicit YutController(QObject *parent = nullptr);
    bool gamestart;

signals:

public slots:
    //setupdialog view
    void setValueOfMals(int val);
    void setValueOfTeams(int val);

private:
    MainWindow * mw;
    YutModel* ymodel;

};

#endif // YUTCONTROLLER_H
