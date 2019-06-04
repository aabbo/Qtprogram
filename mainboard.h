#ifndef MAINBOARD_H
#define MAINBOARD_H

#include "boardbutton.h"
#include "yutmodel.h"
#include <QtWidgets>
#include <QVector>
#include <QGridLayout>

class MainBoard : public QWidget
{
    Q_OBJECT

public:
    //MainBoard(vector<BoardButton*> btnList,QWidget* parent = nullptr);
    MainBoard( QWidget* parent = nullptr);
    void setBoard();

public:
    QGridLayout* grid;
    QVector<QPushButton*> buttonList;
    // 26 : 28, 24 방향으로만 가능(0,0)
    // 25 : 28, 27 방향으로만 가능(0,1)
    int recentButton;
private:
    QWidget* parent;
};

#endif // MAINBOARD_H
