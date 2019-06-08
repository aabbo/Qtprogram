#include "mainteams.h"
#include <QLabel>
#include <QDebug>

MainTeams::MainTeams(int teamNum, int malNum, QWidget *parent) : QWidget(parent)
{
    mal=new QGridLayout();
    result = new QGridLayout();
    this->parent = parent;
    setTeams(teamNum, malNum);
}
void MainTeams::setTeams(int totalTeamNum, int totalMalNum){

    QLabel* label0=new QLabel();
    label0->setText("나간 말");
    label0->setMaximumHeight(50);
    label0->setMinimumSize(50,50);
    result->addWidget(label0,0,0);

    QLabel* tmpLabel = new QLabel();
    tmpLabel->setMaximumSize(50,50);
    tmpLabel->setMinimumSize(50,50);
    mal->addWidget(tmpLabel,0,0);

    for(int i=1;i<=totalTeamNum;i++){
        //team name
        QLabel* teamName=new QLabel();
        teamName->setText("팀"+QString::number(i));
        teamName->setAlignment(Qt::AlignCenter);
        teamName->setMaximumSize(50,50);
        teamName->setMinimumSize(50,50);
        this->teamLabelList.push_back(teamName);
        mal->addWidget(teamName,i,0);

        QLabel* outtedMal = new QLabel();
        outtedMal->setMaximumSize(50,50);
        outtedMal->setMinimumSize(50,50);
        this->resutlLabelList.push_back(outtedMal);
        result->addWidget(outtedMal,i,0);

        QVector<QPushButton*> tmpVec;
        for(int j=0;j<totalMalNum;j++){
            QPushButton* btn=new QPushButton();
            tmpVec.push_back(btn);
            btn->setDisabled(true);
            btn->setObjectName("Remained");
            btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            btn->setMinimumSize(50,50);
            btn->setMaximumSize(50,50);
            mal->addWidget(btn,i,j+1);
            connect(btn, SIGNAL(clicked()), parent, SLOT(MalClicked()));
        }
        this->MalButtonList.push_back(tmpVec);
        tmpVec.clear();
    }
}

void MainTeams::setButtonStyleSheetAll(QString style, int totalTeamNum, QVector<int> remainMalNum, QVector<int> outtedMalNum){
    int totalMalNum = this->MalButtonList[0].size();
    for(int i=1; i<=totalTeamNum; i++){
        for(int j=0; j<totalMalNum; j++){
            if(remainMalNum[i-1]<=j){
                this->MalButtonList.at(i-1).at(j)->setVisible(false);
                continue;
            }
            else{
                this->MalButtonList.at(i-1).at(j)->setVisible(true);
            }
            QString imageUrl = ":/img/team" + QString::number(i)+".png";
            QString styleBtn = "image:url(" + imageUrl + ");" + style;
            this->MalButtonList.at(i-1).at(j)->setStyleSheet(styleBtn);
        }
        QString imageUrl = ":/img/team" + QString::number(i) + "_" + QString::number(outtedMalNum[i-1])+".png";
        QString styleBtn = "image:url(" + imageUrl + ");" + style;
        this->resutlLabelList.at(i-1)->setStyleSheet(styleBtn);
    }


}

void MainTeams::setButtonStyle(QString style, int teamNum, int remainedMalNum){
    QString imageUrl = ":/img/team" + QString::number(teamNum) + ".png";
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

void MainTeams::setButtonDisable(int teamNum, int remainedMalNum){
    for(int i=0; i<remainedMalNum; i++){
        this->MalButtonList[teamNum-1].at(i)->setDisabled(true);
    }
}
