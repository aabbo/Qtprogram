#include "mainteams.h"
#include <QLabel>
#include <QDebug>

MainTeams::MainTeams(int teamNum, int malNum, QWidget *parent) : QWidget(parent)
{
    grid=new QGridLayout();
    this->parent = parent;
    setTeams(teamNum, malNum);
}
void MainTeams::setTeams(int totalTeamNum, int totalMalNum){

//    QLabel* label0=new QLabel();
//    label0->setText("게임전");
//    label0->setMaximumSize(50,80);
//    label0->setMinimumSize(50,80);
//    grid->addWidget(label0,0,1);

//    QLabel* label1=new QLabel();
//    label1->setText("게임중");
//    label1->setMaximumSize(50,80);
//    label1->setMinimumSize(50,80);
//    grid->addWidget(label1,0,2);

//    QLabel* label2=new QLabel();
//    label2->setText("탈출");
//    label2->setMaximumSize(50,80);
//    label2->setMinimumSize(50,80);
//    grid->addWidget(label2,0,3);

    for(int i=1;i<=totalTeamNum;i++){
        //team name
        QLabel* teamName=new QLabel();
        teamName->setText("팀"+QString::number(i));
        teamName->setAlignment(Qt::AlignCenter);
        teamName->setMaximumSize(50,50);
        teamName->setMinimumSize(50,50);
        this->teamLabelList.push_back(teamName);
        grid->addWidget(teamName,i,0);

        QVector<QPushButton*> tmpVec;
        for(int j=0;j<totalMalNum;j++){
            QPushButton* btn=new QPushButton();
            tmpVec.push_back(btn);
            btn->setDisabled(true);
            btn->setObjectName("Remained");
            btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            btn->setMinimumSize(50,50);
            btn->setMaximumSize(50,50);
            grid->addWidget(btn,i,j+1);
            connect(btn, SIGNAL(clicked()), parent, SLOT(MalClicked()));
        }
        this->MalButtonList.push_back(tmpVec);
        tmpVec.clear();
    }
}

void MainTeams::setButtonStyleSheetAll(QString style, int totalTeamNum, QVector<int> remainMalNum){
    int totalMalNum = this->MalButtonList[0].size();
    for(int i=1; i<=totalTeamNum; i++){
        for(int j=0; j<totalMalNum; j++){
            if(remainMalNum[i-1]<=j){
                this->MalButtonList.at(i-1).at(j)->setVisible(false);
                continue;
            }
            QString imageUrl = ":/img/team" + QString::number(i)+"_0.png";
            QString styleBtn = "image:url(" + imageUrl + ");" + style;
            this->MalButtonList.at(i-1).at(j)->setStyleSheet(styleBtn);
        }
    }
}

void MainTeams::setButtonStyle(QString style, int teamNum, int remainedMalNum){
    QString imageUrl = ":/img/team" + QString::number(teamNum) + "_0.png";
    QString styleBtn = "image:url(" + imageUrl + ");" + style;
    for(int i=0; i<remainedMalNum; i++)
        this->MalButtonList.at(teamNum-1).at(i)->setStyleSheet(styleBtn);
}

void MainTeams::setLabelStyleSheet(int teamNum, QString style){
    int size = this->teamLabelList.size();
    for(int i=0; i<size; i++)
        if(i == teamNum-1)
            this->teamLabelList[i]->setStyleSheet(style);
        else {
            this->teamLabelList[i]->setStyleSheet("");
        }
}

void MainTeams::setButtonEnable(int teamNum, int remainedMalNum){
    for(int i=0; i<remainedMalNum; i++){
        this->MalButtonList[teamNum-1].at(i)->setDisabled(false);
    }
}
