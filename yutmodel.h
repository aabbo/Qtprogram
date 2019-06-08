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

    QVector<int> outtedMalNum; // 현재 진행중인 팀의 나간 말 정보, 게임이 끝날때까지 초기화하면 안됨

    int firstClickedButtonNum; // Queue에서 말을 한개 꺼낼때 마다 갱신
    int clickedButtonNum; // 마지막으로 클릭한 위치
    bool onBoard; // 클릭할 때 마다 갱신.
    bool isOutted; // 사용자가 선택한 말이 나갔는지 아닌지 검사하기 위한 변수. 0번 버튼에서 도 이상이 나왔을 경우 True.
    bool isWrongClicked; // 사용자가 클릭을 제대로 했는지 검사.
    bool isGameEnd;
    int winningTeamNum;

private:

    int currentTeamNum = 1; // 현재 진행중인 팀 정보, Queue가 다 비었을때만 초기화
    QVector<int> remainMalNum; // 현재 진행중인 팀의 남아있는 말 정보, 게임이 끝날때까지 초기화하면 안됨.
    QQueue<int> teamYutInfo; // 현재 진행중인 팀이 던진 윷 정보, 해당 정보는 팀별로 저장할 필요가 없다. 턴이 넘어갈 때 초기화
    QMap<int, QVector<QPair<int, int> > > malLocation; // 현재 메인 보드 위에 존재하는 말의 정보, 게임 끝날때까지 저장하고 있어야 함.
    QVector<int> clickableLocation; // 현재 선택 가능한 보드위의 버튼 정보, Queue에서 윷 정보를 꺼낼 때 마다 초기화해야 함.
    QVector<bool> isMalExist; // 잡기 구현할 때 사용
    QVector<BoardButton*> buttonList; // 현재 배치된 모든 버튼의 정보, 게임 끝날때까지 유지해야함.
    QVector<bool> buttonEnable; // 현재 버튼이 클릭 가능한지 판단. 수시로 갱신되어야함.
    QVector<int> prevClickedLoc;

public :
    void setValueOfMals(int val);
    void setValueOfTeams(int val);
    void setMainBoardButtonEnable(int index, bool isEnable);
    bool set_clickedYut(int yut);//if user click yut
    void setButtonDisableAll();
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
    QPair<int, int> getSpecificLocationInfo(int location);

    bool calcFromStartButton();
    void calcFromBoardButton();

    bool isQueueEmpty();

    void endTurn();

    void clearClickableLoc();

    void showAllLocation();

private:
    void setQQueueTeams(int teams);
    void setButtonList();


};

#endif // YUTMODEL_H
