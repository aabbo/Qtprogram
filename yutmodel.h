#ifndef YUTMODEL_H
#define YUTMODEL_H

#include <QQueue>
#include <QMap>
#include <QVector>
#include <QPair>
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
    QMap<int, QVector<QPair<int, int>>> malLocation;
    QVector<int> clickableLocation;
    QVector<bool> isMalExist; // 잡기 구현할 때 사용
    QVector<BoardButton*> buttonList;
    QVector<bool> buttonEnable;


public :
    void setValueOfMals(int val);
    void setValueOfTeams(int val);
    void setMainBoardButtonEnable(int index, bool isEnable);
    bool set_clickedYut(int yut);//if user click yut
    bool updateBoardButton();

    bool getMainBoardButtonEnable(int index);
    QQueue<int> getCurrentQueue();
    QVector<int> getAllRemainMalNum();
    QVector<int> getAllOuttedMalNum();
    int getCurrentTeamRemainMalNum();
    int getCurrentTeamOuttedMalNum();
    int getCurrentTeamNum();
    int getCurrentButtonMalNum();
    QVector<int> getCurrentClickableLocation();
    QVector<bool> getMalExistVec();
    QVector<QPair<int,int>> getCurrentMalLocation();
    QMap<int, QVector<QPair<int,int> > > getAllMalLocation();

    bool calcFromStartButton();
    void calcFromBoardButton();

    bool isQueueEmpty();

    void endTurn();

private:
    void setQQueueTeams(int teams);
    void setButtonList();
    void setButtonDisableAll();

};

#endif // YUTMODEL_H
