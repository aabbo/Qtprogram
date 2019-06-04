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

    int clickedButtonNum;

    QQueue<int> Teams;
    QQueue<int> yutResults; //=> QMap으로 통합

    QVector<BoardButton*> buttonList;

public :
    void setValueOfMals(int val);
    void setValueOfTeams(int val);
    bool set_clickedYut(int yut);//if user click yut

private:
    void setQQueueTeams(int teams);
    void setButtonList();

};

#endif // YUTMODEL_H
