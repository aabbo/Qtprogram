#include "yutmodel.h"
#include <QDebug>
YutModel::YutModel()
{
    numOfMal=2;
    numOfTeam=2;

    //QQueue<int> Teams;
    //QQueue<int> yutResults;

    //vector<BoardButton*> buttonList;
}

//set setupdialog.cpp
void YutModel:: setValueOfMals(int val){
     qDebug()<<"model mal="<<val;
}
void YutModel:: setValueOfTeams(int val){
     qDebug()<<"model team="<<val;
}
