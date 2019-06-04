#include "boardsetthread.h"
#include <QDebug>

BoardSetThread::BoardSetThread(QObject *parent) : QThread(parent), parent(parent)
{
    connect(this, SIGNAL(threadEnd()), parent, SLOT(malSetEnd()));
    connect(this, SIGNAL(updateEnableMal()), parent, SLOT(updateEnableMal()));
}

void BoardSetThread::run(){
    while(this->check){
        // 이동 가능한 말 화면에 표시
        emit updateEnableMal();
        this->isMalClicked = false;
        this->isBoardButtonClicked = false;
        while(!this->isMalClicked){
            // 사용자가 말을 선택할때까지 대기
            if(!this->check)
                break;
        }
        while(!this->isBoardButtonClicked){
            // 사용자가 특정 위치를 선택할때까지 대기
            if(!this->check)
                break;
        }
    }
    qDebug() << "thread end";
    emit threadEnd();
}

void BoardSetThread::malClicked(){
    this->isMalClicked = true;
}

void BoardSetThread::boardButtonClicked(){
    this->isBoardButtonClicked = true;
}

void BoardSetThread::updateQueue(bool isEmpty){
    this->check = !isEmpty;
}

void BoardSetThread::init(){
    this->check = true;
    this->isMalClicked = false;
    this->isBoardButtonClicked = false;
}
