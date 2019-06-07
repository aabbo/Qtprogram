#ifndef MAINBOARD_H
#define MAINBOARD_H

#include "boardbutton.h"
#include "yutmodel.h"
#include <QtWidgets>
#include <QVector>
#include <QMap>
#include <QPair>
#include <QGridLayout>

class MainBoard : public QWidget
{
    Q_OBJECT

public:
    //MainBoard(vector<BoardButton*> btnList,QWidget* parent = nullptr);
    MainBoard( QWidget* parent = nullptr);
    void setBoard();
    // 모든 위치를 일괄 업데이트
    void boardUiUpdate(QMap<int, QVector<QPair<int, int>>> malLocation, int currentTeam, bool highlight);
    void setButtonStyleSheet(int num, QString style);
    void setButtonStyleSheet(int num, int teamNum, int malNum, QString style);

    // initialize
    void setButtonStyleSheetAll(QString style);

public:
    QGridLayout* grid;
    QVector<QPushButton*> buttonList;
    // 26 : 28, 24 방향으로만 가능(0,0)
    // 25 : 28, 27 방향으로만 가능(0,1)

private:
    QWidget* parent;
    const QString ButtonStyle = "border-color:rgb(0,0,0); border-width:1.2px; border-style:solid;"
                                     "border-radius:25px;";
    const QString ButtonBorderHighlight = "border-color:rgb(0,0,0); border-width:3.5px; border-style:solid;"
                                          "border-radius:25px;";
    const QString HighlightStyle = "image : url(:/img/highlight.png);";
    const QString initStyle = "";
};

#endif // MAINBOARD_H
