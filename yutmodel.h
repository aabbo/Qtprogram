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

    // key : teamNumber
    // value : yut throw result
    QMap<int, QQueue<int>> teamInfo;

//    QQueue<int> Teams;
//    QQueue<int> yutResults; //=> QMap으로 통합

    QVector<BoardButton*> buttonList;
private:
    int currentTeamNum = 1;

public :
    void setValueOfMals(int val);
    void setValueOfTeams(int val);
    bool set_clickedYut(int yut);//if user click yut

    QQueue<int> getCurrentQueue();

private:
    void setQQueueTeams(int teams);
    void setButtonList();

};

#endif // YUTMODEL_H
