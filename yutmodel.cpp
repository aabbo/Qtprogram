#include "yutmodel.h"
#include <QDebug>

YutModel::YutModel(int numOfTeam, int numOfMal) : numOfMal(numOfMal), numOfTeam(numOfTeam)
{
    numOfMal=2;
    numOfTeam=2;
    this->currentTeam = 1;
    setButtonList();
}

//================================================================
//
// before game start, setup
//
//================================================================
///**
// * @brief YutModel::setValueOfMals
// * @param val
// * 전체 말 개수 설정
// */
//void YutModel:: setValueOfMals(int val){
//     qDebug()<<"model mal="<<val;
//     this->numOfMal=val;
//}

///**
// * @brief YutModel::setValueOfTeams
// * @param val
// * 전체 팀 수 설정
// */
//void YutModel:: setValueOfTeams(int val){
//     qDebug()<<"model team="<<val;
//     this->numOfTeam=val;
//}

/** set teams queue
 * @brief YutModel::setQQueueTeams
 * @param teams
 * 팀별
 */
void YutModel::setQQueueTeams(int teams){
    if(this->teams.size()!=teams){
        for(int i=1;i<=teams;i++){ //start idx from "1"
            QQueue<int> tmpQueue;
            QVector<int> tmpVector;
            this->teams.insert(i, tmpQueue);
            this->teamMalLocation.insert(i, tmpVector);
        }
    }
}

/**
 * @brief YutModel::setButtonList
 * 윷 정보 초기화
 */
void YutModel::setButtonList(){
    for(int i=0;i<29;i++){
        BoardButton* btn=new BoardButton();
        btn->setObjectName(QString::number(i));
        btn->setDisabled(true);
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
        this->teams[this->currentTeam].push_back(yut);
        //yutResults.push_back(mYut);
        //yut button setdisable
        //move mal -> update mal which can moved
        return true;
    }else if(mYut==4 || mYut==5){
        this->teams[this->currentTeam].push_back(yut);
        //yutResults.push_back(mYut);
        //one more time
        return false;
    }
    return true;
}

bool YutModel::isQueueEmpty(){
    return this->teams[this->currentTeam].empty();
}

int YutModel::getYut(){
    return this->teams[this->currentTeam].dequeue();
}

void YutModel::setButtonEnable(int num){
    if(this->teamMalLocation[this->currentTeam].empty()){
        BoardButton* btn = this->buttonList.at(1);
        for(int i=1; i<num; i++){
            btn = btn->nextStep.at(0);
        }
        btn->setDisabled(false);
        //btn->setEnabled(true);
        btn->setStyleSheet("background-color:red;");
        qDebug() << btn->objectName();
    }
    else{
        for(auto itr = this->teamMalLocation[this->currentTeam].begin(); itr !=
            this->teamMalLocation[this->currentTeam].end(); ++itr){

        }
    }
}

QQueue<int> YutModel::getCurrentYutQueue(){
    return this->teams[this->currentTeam];
}

int YutModel::getLastYutInfo(){
    return this->teams[this->currentTeam].back();
}

QVector<BoardButton*> YutModel::getButtonList(){
    return this->buttonList;
}

void YutModel::updateCurrentTeamInfo(){
    this->currentTeam++;
    if(this->currentTeam > this->numOfTeam){
        this->currentTeam = 1;
    }
}

void YutModel::updateBoardBtnInfo(int index){
    BoardButton* btn = this->buttonList.at(index);
    btn->team = this->currentTeam;
    btn->mals++;
}
