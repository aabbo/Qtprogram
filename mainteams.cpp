#include "mainteams.h"
#include <QDebug>

MainTeams::MainTeams(YutModel* model, YutController* ctrl,QWidget *parent) : QWidget(parent)
{
    this->ymodel=model;
    this->yctrl=ctrl;
    this->parent=parent;

    grid=new QGridLayout();
    setTeams();
}
void MainTeams::setTeams(){

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

    for(int i=1;i<=this->ymodel->numOfTeam;i++){
        //team name
        QLabel* teamName=new QLabel();
        teamName->setObjectName(QString::number(i));
        teamName->setText("team"+QString::number(i));
        teamName->setMaximumSize(50,50);
        teamName->setMinimumSize(50,50);
        teamName->setAutoFillBackground(true);
        this->labelInfo.push_back(teamName);
        if(i == 1){
            setCurrentTeam(i);
        }
        grid->addWidget(teamName,i,0);

        int arr[3]={ymodel->numOfMal,0,0};
        for(int j=0;j<3;j++){
            QPushButton* btn=new QPushButton();
            btn->setDisabled(true);
            if(j==0){
                btn->setObjectName("beforeGame");
            }
            btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            btn->setMinimumSize(50,50);
            btn->setMaximumSize(50,50);
//            btn->setText(QString::number(arr[j]));
            QString imageUrl = ":/img/team" + QString::number(i) + "_" + QString::number(arr[j]) + ".png";
            QString stylebtn = "image: url(" + imageUrl + "); border-color:rgb(0,0,0); border-width:1.2px; border-style:solid;"
                            "border-radius:25px;";
            btn->setStyleSheet(stylebtn);
            grid->addWidget(btn,i,j+1);
            if(j==0){
                connect(btn, SIGNAL(clicked()), parent, SLOT(clickedBeforeMal()));
            }
        }
    }
}

void MainTeams::setCurrentTeam(int num){
    QString style = "QLabel{background-color:rgba(0,0,255,50%);}";
    this->labelInfo.at(num-1)->setStyleSheet(style);
}

