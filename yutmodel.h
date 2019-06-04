#ifndef YUTMODEL_H
#define YUTMODEL_H

#include <QQueue>
#include <QMap>
#include <QVector>
#include "boardbutton.h"

class YutModel
{
public:
    YutModel(int totalTeamNum, int totalMalNum);

public:
    const int numOfMal;
    const int numOfTeam;

    QVector<int> remainMalNum;
    QVector<int> outtedMalNum;

    int clickedButtonNum;


private:
    int currentTeamNum = 1;
    // key : teamNumber
    // value : yut throw result
    QMap<int, QQueue<int>> teamInfo;
    QMap<int, QVector<int>> malLocation;
    QMap<int, QVector<int>> clickableLocation;
    QVector<BoardButton*> buttonList;

public :
    void setValueOfMals(int val);
    void setValueOfTeams(int val);
    bool set_clickedYut(int yut);//if user click yut

    QQueue<int> getCurrentQueue();
    QVector<int> getCurrentClickableLocation();
    QVector<int> getCurrentMalLocation();

private:
    void setQQueueTeams(int teams);
    void setButtonList();

};

#endif // YUTMODEL_H
