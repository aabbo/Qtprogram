#include "yutcontroller.h"
#include <QtDebug>

YutController::YutController(QObject *parent) : QObject(parent)
{
    //View
    //setup dialog
    sd = new SetupDialog(nullptr,this);
    sd->exec();
    gamestart = sd->GetStartBool();

    //Model
    ymodel = new YutModel(sd->totalTeamNum, sd->totalMalNum);

    //mainwindow
    mw = new MainWindow(nullptr,ymodel,this);
    if(gamestart==true){

        mw->show();
    }

    // ready thread
    this->thread = new BoardSetThread(this);
    connect(this, SIGNAL(updateQueue(bool)), thread, SLOT(updateQueue(bool)));
    connect(this, SIGNAL(malClicked()), thread, SLOT(malClicked()));
    connect(this, SIGNAL(boardButtonClicked()), thread, SLOT(boardButtonClicked()));
    connect(this, SIGNAL(threadInit()), thread, SLOT(init()));
}
void YutController::clickedBoardBtn(int num){
    // board button을 클릭하는 경우는 2가지
    // 1. 출발할 말 선택
    // 2. 선택한 말을 놓을 때
    this->ymodel->clickedButtonNum = num;
    if(boardSet){
        this->ymodel->firstClickedButtonNum = num;
        this->boardSet = false;
        this->ymodel->onBoard=true;
        this->ymodel->calcFromBoardButton();

        if(this->ymodel->isOutted){
            this->ymodel->outtedMalNum[this->ymodel->getCurrentTeamNum()-1]++;
            this->ymodel->updateBoardButton();
            mw->setMainBoardUpdate();
            this->ymodel->isOutted = false;
            emit malClicked();
            emit boardButtonClicked();
            emit updateQueue(this->ymodel->isQueueEmpty());
            return;
        }
        this->ymodel->setButtonDisableAll();
        mw->enableCurrentBoardButtonLocation();
//        this->ymodel->clearClickableLoc();
        emit malClicked();
    }
    else{
        bool status = this->ymodel->updateBoardButton();
        if(status && !this->ymodel->isWrongClicked){
            // 말 잡음
        }
        else if(!this->ymodel->isWrongClicked && !status){
            // 말 잡기 x
            mw->setMainBoardUpdate();

            emit boardButtonClicked();
            emit updateQueue(this->ymodel->isQueueEmpty());
            return;
        }
        else if(this->ymodel->isWrongClicked){
            if(this->ymodel->onBoard){
                this->boardSet = true;
                this->clickedBoardBtn(num);
            }
            else{
                this->clickedRemainedMal();
            }
            this->ymodel->isWrongClicked = false;
            return;
        }
    }

}

void YutController::clickedRemainedMal(){
    bool status = true;
    status = this->ymodel->calcFromStartButton();
    this->ymodel->onBoard = false;
    if(status){
        // 이동 가능
        // 이동 가능한 위치 하이라이팅
        this->ymodel->setButtonDisableAll();
        mw->enableCurrentBoardButtonLocation();
        emit malClicked();
    }
    else{
        // 처음부터 빽도
        if(this->ymodel->getCurrentTeamRemainMalNum() == 5){
            // 보드에 말이 올라가 있지 않은 상황에 빽도
            // 턴 종료
            emit boardButtonClicked();
            emit updateQueue(this->ymodel->isQueueEmpty());
        }
        else{
            // 보드에 말이 올라가 있는 상황에 빽도
            // 다른 말 선택 유도

        }
    }
    this->boardSet = false;
    mw->malHighlightCanclation();
}

void YutController::clickedYut(int yut){
    bool status = this->ymodel->set_clickedYut(yut);
    mw->afterClickYut(status);
}

void YutController::setStart(){
    this->boardSet = true;
    emit threadInit();
    this->thread->start();
}

void YutController::malSetEnd(){
    // mainWindow 화면 update
    this->ymodel->endTurn();
    mw->endTurn();
}

void YutController::updateEnableMal(){
    mw->setEnableMalButton();
}
