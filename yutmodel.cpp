#include "yutmodel.h"
#include <QDebug>

YutModel::YutModel(int totalTeamNum, int totalMalNum) : numOfMal(totalMalNum), numOfTeam(totalTeamNum)
{
    this->remainMalNum.fill(totalMalNum, totalTeamNum);
    this->outtedMalNum.fill(0, totalTeamNum);

    QVector<int> tmp;
    for(int i=1; i<=totalTeamNum;i++){
        this->malLocation.insert(i, tmp);
    }

    this->clickedButtonNum = 0;

    setButtonList();
}

//================================================================
//
// before game start, setup
//
//================================================================
/** set teams queue
 * @brief YutModel::setQQueueTeams
 * @param teams
 */
void YutModel::setQQueueTeams(int teams){
    if(this->teamYutInfo.size()!=teams){
        for(int i=1;i<=teams;i++){ //start idx from "1"
            QQueue<int> tmpQueue;
            this->teamYutInfo.insert(i, tmpQueue);
        }
    }
}

/**
 * @brief YutModel::setButtonList
 */
void YutModel::setButtonList(){
    for(int i=0;i<29;i++){
        BoardButton* btn=new BoardButton(i);
        this->buttonList.push_back(btn);
    }
    BoardButton* btn = new BoardButton(30);
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
                tmpBtn->nextStep.push_back(this->buttonList[i+1]);
                tmpBtn->prevStep.push_back(this->buttonList[i-1]);
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

//================================================================
//
// game start
//
//================================================================
/**
 * @brief YutModel::set_clickedYut
 * @param yut
 * -1 : random yut
 * 0 : bbaek do
 * 1 : do
 * 2 : gae
 * 3 : gul
 * 4 : yut
 * 5 : mo
 */
bool YutModel::set_clickedYut(int yut){
    int mYut=yut;
    if(yut==-1){
        mYut=rand()%6;
    }
    //show yut img
    //show yut result list

    if(mYut==0 || mYut==1 || mYut==2 ||mYut==3){
        this->teamYutInfo[this->currentTeamNum].enqueue(mYut);
        //yut button setdisable
        //move mal -> update mal which can moved
        return true;
    }else if(mYut==4 || mYut==5){
        this->teamYutInfo[this->currentTeamNum].enqueue(mYut);
        //one more time
        return false;
    }
    return true;
}

bool YutModel::isQueueEmpty(){
    return this->teamYutInfo[this->currentTeamNum].isEmpty();
}

QQueue<int> YutModel::getCurrentQueue(){
    return this->teamYutInfo[this->currentTeamNum];
}

QVector<int> YutModel::getCurrentClickableLocation(){
    return this->clickableLocation;
}

QVector<int> YutModel::getCurrentMalLocation(){
    return this->malLocation[this->currentTeamNum];
}

QVector<int> YutModel::getAllOuttedMalNum(){
    return this->outtedMalNum;
}

QVector<int> YutModel::getAllRemainMalNum(){
    return this->remainMalNum;
}

int YutModel::getCurrentTeamOuttedMalNum(){
    return this->outtedMalNum[this->currentTeamNum-1];
}

int YutModel::getCurrentTeamRemainMalNum(){
    return this->remainMalNum[this->currentTeamNum-1];
}

int YutModel::getCurrentTeamNum(){
    return this->currentTeamNum;
}

bool YutModel::calcFromStartButton(){
    int yutNum = this->teamYutInfo[this->currentTeamNum].dequeue();
    BoardButton* btn = this->buttonList[1];
    if(yutNum == 0){
        return false;
    }
    for(int i=1; i<yutNum; i++){
        btn = btn->nextStep[0];
    }
    this->clickableLocation.push_back(btn->num);
    this->remainMalNum[this->currentTeamNum-1] -= 1;
    return true;
}

void YutModel::calcFromBoardButton(){

}

bool YutModel::setBoardButton(){
    BoardButton* btn = this->buttonList[this->clickedButtonNum];
    if(!btn->mals){
        // 빈칸
        btn->mals++;
        btn->team = this->currentTeamNum;
        this->malLocation[this->currentTeamNum].push_back(btn->num);
        return false;
    }
}

int YutModel::getCurrentButtonMalNum(){
    BoardButton* btn = this->buttonList[this->clickedButtonNum];
    return btn->mals;
}

void YutModel::endTurn(){
    this->clickableLocation.clear();
    this->currentTeamNum++;
    if(this->currentTeamNum > this->numOfTeam)
        this->currentTeamNum = 1;
}
