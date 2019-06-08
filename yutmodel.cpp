#include "yutmodel.h"
#include <QDebug>
#include <QTime>

YutModel::YutModel(int totalTeamNum, int totalMalNum) : numOfMal(totalMalNum), numOfTeam(totalTeamNum)
{
    this->remainMalNum.fill(totalMalNum, totalTeamNum);
    this->outtedMalNum.fill(0, totalTeamNum);
    this->prevClickedLoc.fill(0, totalTeamNum);

    QVector<QPair<int, int>> tmp;
    for(int i=1; i<=totalTeamNum;i++){
        this->malLocation.insert(i, tmp);
    }

    this->clickedButtonNum = 1;
    this->isOutted = false;
    this->isWrongClicked = false;
    this->isGameEnd = false;

    setButtonList();
}

//================================================================
//
// before game start, setup
//
//================================================================
/**
 * @brief YutModel::setButtonList
 */
void YutModel::setButtonList(){
    for(int i=0;i<29;i++){
        BoardButton* btn=new BoardButton(i);
        this->buttonList.push_back(btn);
        this->buttonEnable.push_back(false);
    }
    BoardButton* btn = new BoardButton(30);
    this->buttonList.push_back(btn);
    this->buttonEnable.push_back(false);

    for(int i=0; i<20; i++){
        BoardButton* tmpBtn = this->buttonList[i];
        if(i < 19){
            if(i == 0){
                tmpBtn->nextStep.push_back(this->buttonList[1]);
                tmpBtn->nextStep.push_back(this->buttonList[29]);
                tmpBtn->prevStep.push_back(this->buttonList[19]);
                tmpBtn->prevStep.push_back(this->buttonList[20]);
            }
            else if(i==5){
                tmpBtn->nextStep.push_back(this->buttonList[6]);
                tmpBtn->prevStep.push_back(this->buttonList[4]);
                tmpBtn->nextStep.push_back(this->buttonList[21]);
                tmpBtn->prevStep.push_back(this->buttonList[4]);
            }
            else if(i==10){
                tmpBtn->nextStep.push_back(this->buttonList[11]);
                tmpBtn->prevStep.push_back(this->buttonList[9]);
                tmpBtn->nextStep.push_back(this->buttonList[22]);
                tmpBtn->prevStep.push_back(this->buttonList[9]);
            }
            else if(i == 15){
                tmpBtn->nextStep.push_back(this->buttonList[16]);
                tmpBtn->nextStep.push_back(this->buttonList[16]);
                tmpBtn->prevStep.push_back(this->buttonList[14]);
                tmpBtn->prevStep.push_back(this->buttonList[23]);
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

    this->buttonList[28]->nextStep.push_back(this->buttonList[27]);
    this->buttonList[28]->nextStep.push_back(this->buttonList[24]);
    this->buttonList[28]->prevStep.push_back(this->buttonList[25]);
    this->buttonList[28]->prevStep.push_back(this->buttonList[26]);

    this->buttonList[29]->nextStep.push_back(this->buttonList[0]);

}

void YutModel::setMainBoardButtonEnable(int index, bool isEnable){
    this->buttonEnable[index] = isEnable;
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
    qsrand(QTime::currentTime().msecsSinceStartOfDay());
    int mYut=yut;
    if(yut==-1){
        mYut=qrand()%6;
    }
    //show yut img
    //show yut result list

    if(mYut==0 || mYut==1 || mYut==2 ||mYut==3){
        this->teamYutInfo.enqueue(mYut);
        //yut button setdisable
        //move mal -> update mal which can moved
        return true;
    }else if(mYut==4 || mYut==5){
        this->teamYutInfo.enqueue(mYut);
        //one more time
        return false;
    }
    return true;
}

bool YutModel::isQueueEmpty(){
    return this->teamYutInfo.isEmpty();
}

bool YutModel::getMainBoardButtonEnable(int index){
    return this->buttonEnable[index];
}

QQueue<int> YutModel::getCurrentQueue(){
    return this->teamYutInfo;
}

QVector<int> YutModel::getCurrentClickableLocation(){
    return this->clickableLocation;
}

QVector<QPair<int, int>> YutModel::getCurrentMalLocation(){
    return this->malLocation[this->currentTeamNum];
}

QVector<int> YutModel::getAllOuttedMalNum(){
    return this->outtedMalNum;
}

QVector<int> YutModel::getAllRemainMalNum(){
    return this->remainMalNum;
}

QVector<bool> YutModel::getMalExistVec(){
    return this->isMalExist;
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
    // 새로운 말을 선택했을 경우
    int yutNum = this->teamYutInfo.dequeue();
    BoardButton* btn = this->buttonList[1];
    if(yutNum == 0){
        return false;
    }
    for(int i=1; i<yutNum; i++){
        btn = btn->nextStep[0];
    }
    this->clickableLocation.push_back(btn->num);
    if(btn->mals){
        this->isMalExist.push_back(true);
    }
    else {
        this->isMalExist.push_back(false);
    }
    this->remainMalNum[this->currentTeamNum-1] -= 1;
    return true;
}

void YutModel::calcFromBoardButton(){
    // 보드 위에 올라와있는 말을 선택했을 경우
    int yutNum = this->teamYutInfo.dequeue();
    BoardButton* btn = this->buttonList[this->clickedButtonNum];
    switch(this->clickedButtonNum){
    case 0:
    case 5:
    case 10:
    case 15:
    case 28:
        if(yutNum  == 0){
            //빽도
            btn = btn->prevStep[this->prevClickedLoc[this->currentTeamNum-1]];
            if(btn->mals){
                this->isMalExist.push_back(true);
            }else{
                this->isMalExist.push_back(false);
            }
            this->clickableLocation.push_back(btn->num);
        }
        else{
            if(this->onBoard){
                for(int i=0; i<yutNum; i++){
                    if(i < yutNum && btn->num == 0){
                        this->isOutted = true;
                        break;
                    }
                    btn = btn->nextStep[0];
                }
                if(this->isOutted)
                    break;
                if(btn->mals){
                    this->isMalExist.push_back(true);
                }
                else{
                    this->isMalExist.push_back(false);
                }
                this->clickableLocation.push_back(btn->num);


                btn = this->buttonList[this->clickedButtonNum];
                for(int i=0; i<yutNum; i++){
                    if(!i)
                        btn = btn->nextStep[1];
                    else{
                        if(i < yutNum && btn->num == 0){
                            this->isOutted = true;
                            break;
                        }
                        if(this->clickedButtonNum == 5 && btn->num == 28)
                            btn = btn->nextStep[0];
                        else if(this->clickedButtonNum == 10 && btn->num == 28)
                            btn = btn->nextStep[1];
                        else
                            btn = btn->nextStep[0];
                    }
                 }
                 this->clickableLocation.push_back(btn->num);
                 if(btn->mals){
                    this->isMalExist.push_back(true);
                 }
                 else{
                    this->isMalExist.push_back(false);
                 }
            }
            else{
                for(int i=1; i<yutNum; i++){
                    btn = btn->nextStep[0];
                }
                if(btn->mals){
                    this->isMalExist.push_back(true);
                }
                else{
                    this->isMalExist.push_back(false);
                }
                this->clickableLocation.push_back(btn->num);


                btn = this->buttonList[this->clickedButtonNum];
                for(int i=0; i<yutNum; i++){
                    if(i < yutNum && btn->num == 0){
                        this->isOutted = true;
                        break;
                    }
                    if(!i)
                        btn = btn->nextStep[1];
                    else
                        btn = btn->nextStep[0];
                 }
                 this->clickableLocation.push_back(btn->num);
                 if(btn->mals){
                    this->isMalExist.push_back(true);
                 }
                 else{
                    this->isMalExist.push_back(false);
                 }
            }
        }
        break;
    default:
        if(yutNum == 0){
            btn = btn->prevStep[0];
            if(btn->mals){
                this->isMalExist.push_back(true);
            }else{
                this->isMalExist.push_back(false);
            }
            this->clickableLocation.push_back(btn->num);
        }
        else{
            if(this->onBoard){
                for(int i=0; i<yutNum; i++){
                    if(i < yutNum && btn->num == 0){
                        this->isOutted = true;
                        break;
                    }
                    btn = btn->nextStep[0];
                }
                if(this->isOutted)
                    break;

                this->clickableLocation.push_back(btn->num);
                if(btn->mals){
                    this->isMalExist.push_back(true);
                }
                else{
                    this->isMalExist.push_back(false);
                }
                break;
            }
            else{
                for(int i=1; i<yutNum; i++){
                    btn = btn->nextStep[0];
                }
                this->clickableLocation.push_back(btn->num);
                if(btn->mals){
                    this->isMalExist.push_back(true);
                }
                else{
                    this->isMalExist.push_back(false);
                }
                break;
            }

        }
    }
}

bool YutModel::updateBoardButton(){
    // false : 말 잡기x
    // true : 말 잡기 ㅇ
    BoardButton* btn;
    if(this->isOutted){
        int removeIndex = 0;
        for(int i=0; i<this->malLocation[this->currentTeamNum].size(); i++){
            if(this->malLocation[this->currentTeamNum][i].first == this->clickedButtonNum){
                removeIndex = i;
                this->outtedMalNum[this->currentTeamNum-1] += this->malLocation[this->currentTeamNum][i].second;
            }
        }
        if(this->outtedMalNum.contains(this->numOfMal)){
            qDebug() << "end game";
            this->isGameEnd = true;
            this->winningTeamNum = this->currentTeamNum;
        }
        this->malLocation[this->currentTeamNum].remove(removeIndex);
        btn = this->buttonList[this->clickedButtonNum];
        btn->mals = 0;

        this->setButtonDisableAll();
        this->clickableLocation.clear();
        this->isMalExist.clear();
        return false;
    }


    btn = this->buttonList[this->clickedButtonNum];
    if(!this->clickableLocation.contains(btn->num)){
        this->isWrongClicked = true;

        this->setButtonDisableAll();
        this->clickableLocation.clear();
        this->isMalExist.clear();

        return false;
    }
    for(int i=0; i<clickableLocation.size(); i++){
        if(clickableLocation[i] == btn->num){
            this->prevClickedLoc[this->currentTeamNum-1] = i%2;
        }
    }
    if(!btn->mals){
        // 빈칸
        btn->team = this->currentTeamNum;
        if(this->onBoard){
            for(int i=0; i<this->malLocation[this->currentTeamNum].size(); i++){
                if(this->malLocation[this->currentTeamNum][i].first == this->firstClickedButtonNum){
                    btn->mals = this->malLocation[this->currentTeamNum][i].second;
                }
            }
        }
        else{
            btn->mals = 1;
        }
        QPair<int, int> tmpPair(btn->num, btn->mals);
        this->malLocation[this->currentTeamNum].push_back(tmpPair);

        if(this->onBoard){
            int removeNum = -1;
            for(int i =0; i<this->malLocation[this->currentTeamNum].size(); i++){
                if(this->malLocation[this->currentTeamNum][i].first == this->firstClickedButtonNum){
                    removeNum = i;
                }
            }
            this->malLocation[this->currentTeamNum].remove(removeNum);
            btn = this->buttonList[this->firstClickedButtonNum];
            btn->mals = 0;
        }
        this->setButtonDisableAll();
        this->clickableLocation.clear();
        this->isMalExist.clear();
        return false;
    }
    else {
        if(btn->team == this->currentTeamNum){
            //업기
            btn->mals++;
            for(int i=0; i<this->malLocation[this->currentTeamNum].size(); i++){
                if(this->malLocation[this->currentTeamNum][i].first == btn->num)
                    this->malLocation[this->currentTeamNum][i].second = btn->mals;
            }
            if(this->onBoard){
                int removeNum = -1;
                for(int i =0; i<this->malLocation[this->currentTeamNum].size(); i++){
                    if(this->malLocation[this->currentTeamNum][i].first == this->firstClickedButtonNum){
                        removeNum = i;
                    }
                }
                this->malLocation[this->currentTeamNum].remove(removeNum);
                btn = this->buttonList[this->firstClickedButtonNum];
                btn->mals = 0;
            }
            this->setButtonDisableAll();
            this->clickableLocation.clear();
            this->isMalExist.clear();
            return false;
        }
        else{
            //잡기
            //버튼에서 잡힌 팀 정보 제거
            this->remainMalNum[btn->team-1] += btn->mals;
            int removeIndex = 0;
            for(int i=0; i<this->malLocation[btn->team].size(); i++){
                if(this->malLocation[btn->team][i].first == btn->num){
                    removeIndex = i;
                }
            }
            this->malLocation[btn->team].remove(removeIndex);

            // 잡은 팀 말 배치
            if(this->onBoard){
                int malNum = 0;
                for(int i=0; i<this->malLocation[this->currentTeamNum].size(); i++){
                    if(this->malLocation[this->currentTeamNum][i].first == firstClickedButtonNum){
                        malNum = this->malLocation[this->currentTeamNum][i].second;
                        removeIndex = i;
                    }
                }
                this->malLocation[this->currentTeamNum].remove(removeIndex);
                btn->team = this->currentTeamNum;
                btn->mals = malNum;
            }
            else{
                btn->mals = 1;
                btn->team = this->currentTeamNum;
            }
            QPair<int, int> tmpPair(this->clickedButtonNum, btn->mals);
            this->malLocation[this->currentTeamNum].push_back(tmpPair);

            this->setButtonDisableAll();
            this->clickableLocation.clear();
            this->isMalExist.clear();
            return true;

        }
    }
}

int YutModel::getCurrentButtonMalNum(){
    BoardButton* btn = this->buttonList[this->clickedButtonNum];
    return btn->mals;
}

void YutModel::endTurn(){
    this->setButtonDisableAll();
    this->clickableLocation.clear();
    this->isMalExist.clear();
    this->teamYutInfo.clear();
    this->currentTeamNum++;
    if(this->currentTeamNum > this->numOfTeam)
        this->currentTeamNum = 1;
}

void YutModel::setButtonDisableAll(){
    for(int i=0; i<30; i++){
        this->buttonEnable[i] = false;
    }
}

QMap<int, QVector<QPair<int, int > > > YutModel::getAllMalLocation(){
    return this->malLocation;
}

void YutModel::clearClickableLoc(){
    this->clickableLocation.clear();
}

QPair<int, int> YutModel::getSpecificLocationInfo(int location){
    for(int i=0; i<this->malLocation.size(); i++){
        for(int j =0; j<this->malLocation[i].size(); j++){
            if(this->malLocation[i][j].first == location)
                return QPair<int, int>(i,this->malLocation[i][j].second);
        }
    }
    return QPair<int, int>();
}
void YutModel::showAllLocation(){
    for(int i=0; i<this->malLocation.size(); i++){
        for(int j=0; j<this->malLocation[i].size(); j++){

        }
    }
}
