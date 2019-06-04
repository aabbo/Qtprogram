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

    QLabel* label0=new QLabel();
    label0->setText("게임전");
    label0->setMaximumSize(50,80);
    label0->setMinimumSize(50,80);
    grid->addWidget(label0,0,1);

    QLabel* label1=new QLabel();
    label1->setText("게임중");
    label1->setMaximumSize(50,80);
    label1->setMinimumSize(50,80);
    grid->addWidget(label1,0,2);

    QLabel* label2=new QLabel();
    label2->setText("탈출");
    label2->setMaximumSize(50,80);
    label2->setMinimumSize(50,80);
    grid->addWidget(label2,0,3);

    for(int i=1;i<=totalTeamNum;i++){
        //team name
        QLabel* teamName=new QLabel();
        teamName->setText("team"+QString::number(i));
        teamName->setMaximumSize(50,50);
        teamName->setMinimumSize(50,50);
        this->teamLabelList.push_back(teamName);
        grid->addWidget(teamName,i,0);

        QVector<QPushButton*> tmpVec;
        for(int j=0;j<3;j++){
            QPushButton* btn=new QPushButton();
            tmpVec.push_back(btn);
            if(j==0){
                btn->setObjectName("beforeGame");
            }
            btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            btn->setMinimumSize(50,50);
            btn->setMaximumSize(50,50);
            grid->addWidget(btn,i,j+1);
            if(j==0){
                connect(btn, SIGNAL(clicked()), parent, SLOT(clickedBeforeMal()));
            }
        }
        this->MalButtonList.push_back(tmpVec);
        tmpVec.clear();
    }
}

void MainTeams::setButtonStyleSheetAll(QString style, int totalTeamNum, int totalMalNum, QVector<int> remainMalNum, QVector<int> outtedMalNum){
    for(int i=1; i<=totalTeamNum; i++){
        int arr[3] = {totalMalNum - remainMalNum.at(i-1), remainMalNum[i-1], outtedMalNum[i]};
        for(int j=0; j<3; j++){
            QString imageUrl = ":/img/team" + QString::number(i)+"_" +QString::number(arr[j]) + ".png";
            QString styleBtn = "image:url(" + imageUrl + ");" + style;
            this->MalButtonList.at(i-1).at(j)->setStyleSheet(styleBtn);
        }
    }
}

void MainTeams::setLabelStyleSheet(int teamNum, QString style){
    this->teamLabelList[teamNum-1]->setStyleSheet(style);
}
