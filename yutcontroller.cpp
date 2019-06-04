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
    qDebug() << "test==ctrl=="<< QString::number(num);
    this->ymodel->clickedButtonNum = num;
    bool status = this->ymodel->setBoardButton();
    if(status){
        // 말 잡음
    }
    else{
        // 말 잡기 x
        mw->setMainBoardUpdate(num, this->ymodel->getCurrentTeamNum(),
                               this->ymodel->getCurrentButtonMalNum());

        emit boardButtonClicked();
        emit updateQueue(this->ymodel->isQueueEmpty());
    }
}

void YutController::clickedRemainedMal(){
    bool status = true;
    status = this->ymodel->calcFromStartButton();
    if(status){
        // 이동 가능
        // 이동 가능한 위치 하이라이팅
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
    mw->malHighlightCanclation();
}

void YutController::clickedYut(int yut){
    qDebug() << "Yut Clicked";
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
