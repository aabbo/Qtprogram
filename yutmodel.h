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
private:
    int currentTeamNum = 1;
    QVector<int> remainMalNum;
    QVector<int> outtedMalNum;
    QMap<int, QQueue<int>> teamYutInfo;
    QMap<int, QVector<int>> malLocation;
    QVector<int> clickableLocation;
    QVector<bool> isMalExist;
    QVector<BoardButton*> buttonList;


public :
    void setValueOfMals(int val);
    void setValueOfTeams(int val);
    bool set_clickedYut(int yut);//if user click yut
    bool setBoardButton();

    QQueue<int> getCurrentQueue();
    QVector<int> getAllRemainMalNum();
    QVector<int> getAllOuttedMalNum();
    int getCurrentTeamRemainMalNum();
    int getCurrentTeamOuttedMalNum();
    int getCurrentTeamNum();
    int getCurrentButtonMalNum();
    QVector<int> getCurrentClickableLocation();
    QVector<bool> getMalExistVec();
    QVector<int> getCurrentMalLocation();

    bool calcFromStartButton();
    void calcFromBoardButton();

    bool isQueueEmpty();

    void endTurn();

private:
    void setQQueueTeams(int teams);
    void setButtonList();

};

#endif // YUTMODEL_H
