#ifndef YUTMODEL_H
#define YUTMODEL_H

#include <QQueue>
#include "boardbutton.h"

class YutModel
{
public:
    YutModel();

public:
    int numOfMal;
    int numOfTeam;

    QQueue<int> Teams;
    QQueue<int> yutResults;

    vector<BoardButton*> buttonList;

public :
    void setValueOfMals(int val);
    void setValueOfTeams(int val);
private:
    void setQQueueTeams(int teams);
    void setButtonList();

};

#endif // YUTMODEL_H
