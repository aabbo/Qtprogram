#include "mainteams.h"
#include <QLabel>
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

    for(int i=0;i<this->ymodel->numOfTeam;i++){
        //team name
        QLabel* teamName=new QLabel();
        teamName->setText("team"+QString::number(i+1));
        teamName->setMaximumSize(50,50);
        teamName->setMinimumSize(50,50);
        grid->addWidget(teamName,i,0);

        int arr[3]={ymodel->numOfMal,0,0};
        for(int j=0;j<3;j++){
            QPushButton* btn=new QPushButton();
            if(j==0){
                btn->setObjectName("beforeGame");
            }
            btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            btn->setMinimumSize(50,50);
            btn->setMaximumSize(50,50);
            btn->setText(QString::number(arr[j]));
            QString stylebtn = "border-color:rgb(0,0,0); border-width:1.2px; border-style:solid;"
                            ;//"border-radius:25px;"
            btn->setStyleSheet(stylebtn);
            grid->addWidget(btn,i,j+1);
            if(j==0){
                connect(btn, SIGNAL(clicked()), parent, SLOT(clickedBeforeMal()));
            }
        }
    }
}

