#ifndef YUTMODEL_H
#define YUTMODEL_H

#include <QQueue>
#include <QMap>
#include <QVector>
#include "boardbutton.h"

class YutModel
{
public:
    YutModel(int numOfTeam, int numOfMal);

public:
    const int numOfMal;
    const int numOfTeam;

private:
    QMap<int, QQueue<int>> teams;
    QMap<int, QVector<int>> teamMalLocation;

    QVector<BoardButton*> buttonList;
    int currentTeam;

public :
    bool set_clickedYut(int yut);//if user click yut
    void setButtonEnable(int num);

    void updateCurrentTeamInfo();
    void updateBoardBtnInfo(int index);

    QQueue<int> getCurrentYutQueue();
    int getLastYutInfo();
    QVector<BoardButton*> getButtonList();
    int getYut();

    bool isQueueEmpty();

private:
    void setQQueueTeams(int teams);
    void setButtonList();

};

#endif // YUTMODEL_H
