#include "yutmodel.h"
#include <QDebug>
YutModel::YutModel()
{
    numOfMal=2;
    numOfTeam=2;
    setButtonList();
    //vector<BoardButton*> buttonList;
}

//================================================================
//
// before game start, setup
//
//================================================================
/**
 * @brief YutModel::setValueOfMals
 * @param val
 */
void YutModel:: setValueOfMals(int val){
     qDebug()<<"model mal="<<val;
     this->numOfMal=val;
}
/**
 * @brief YutModel::setValueOfTeams
 * @param val
 */
void YutModel:: setValueOfTeams(int val){
     qDebug()<<"model team="<<val;
     this->numOfTeam=val;
}
/** set teams queue
 * @brief YutModel::setQQueueTeams
 * @param teams
 */
void YutModel::setQQueueTeams(int teams){
    if(Teams.size()!=teams){
        for(int i=1;i<=teams;i++){ //start idx from "1"
            this->Teams.push_back(teams);
        }
    }
}
/**
 * @brief YutModel::setButtonList
 */
void YutModel::setButtonList(){
    for(int i=0;i<29;i++){
        BoardButton* btn=new BoardButton();
        btn->setObjectName(QString::number(i));
        this->buttonList.push_back(btn);
    }
    BoardButton* btn = new BoardButton();
    btn->setObjectName("end");
    this->buttonList.push_back(btn);

    for(int i=0; i<20; i++){
        BoardButton* tmpBtn = this->buttonList[i];
        if(i < 19){
            if(i == 0){
                tmpBtn->nextStep.push_back(this->buttonList[29]);
                tmpBtn->prevStep.push_back(this->buttonList[19]);
            }
            else if(i==5){
                tmpBtn->nextStep.push_back(this->buttonList[21]);
                tmpBtn->prevStep.push_back(this->buttonList[4]);
            }
            else if(i==10){
                tmpBtn->nextStep.push_back(this->buttonList[22]);
                tmpBtn->prevStep.push_back(this->buttonList[9]);
            }else {
                qDebug()<<"jalo"<<i;
                tmpBtn->nextStep.push_back(this->buttonList[i+1]);
                tmpBtn->prevStep.push_back(this->buttonList[i-1]);
                qDebug()<<"here"<<i;
            }
        }else if(i==19){
            tmpBtn->nextStep.push_back(this->buttonList[0]);
        }
    }
    this->buttonList[20]->nextStep.push_back(this->buttonList[0]);
    this->buttonList[20]->prevStep.push_back(this->buttonList[24]);

    this->buttonList[21]->nextStep.push_back(this->buttonList[25]);
    this->buttonList[21]->prevStep.push_back(this->buttonList[5]);

    this->buttonList[22]->nextStep.push_back(this->buttonList[26]);
    this->buttonList[22]->prevStep.push_back(this->buttonList[10]);

    this->buttonList[23]->nextStep.push_back(this->buttonList[15]);
    this->buttonList[23]->prevStep.push_back(this->buttonList[27]);

    this->buttonList[24]->nextStep.push_back(this->buttonList[20]);
    this->buttonList[24]->prevStep.push_back(this->buttonList[28]);

    this->buttonList[25]->nextStep.push_back(this->buttonList[28]);
    this->buttonList[25]->prevStep.push_back(this->buttonList[21]);

    this->buttonList[26]->nextStep.push_back(this->buttonList[28]);
    this->buttonList[26]->prevStep.push_back(this->buttonList[22]);

    this->buttonList[27]->nextStep.push_back(this->buttonList[23]);
    this->buttonList[27]->prevStep.push_back(this->buttonList[28]);

    this->buttonList[28]->nextStep.push_back(this->buttonList[24]);
    this->buttonList[28]->nextStep.push_back(this->buttonList[27]);
    this->buttonList[28]->prevStep.push_back(this->buttonList[25]);
    this->buttonList[28]->prevStep.push_back(this->buttonList[26]);

    this->buttonList[29]->nextStep.push_back(this->buttonList[0]);

}
