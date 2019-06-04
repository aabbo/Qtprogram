#include "mainboard.h"
#include <QLabel>
//vector<BoardButton*> btnList,QWidget *parent
MainBoard::MainBoard(QWidget *parent) : QWidget(parent)
{
    this->parent=parent;
    grid = new QGridLayout();
    setBoard();
}

void MainBoard::setBoard(){
    int row = 10;
    int col = 10;
    for(int i=0;i<29;i++){
        QPushButton* btn = new QPushButton();
        buttonList.push_back(btn);
        this->buttonList.at(i)->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        this->buttonList.at(i)->setMinimumSize(50,50);
        this->buttonList.at(i)->setMaximumSize(50,50);
        this->buttonList.at(i)->setText(QString::number(i));
        this->buttonList.at(i)->setObjectName(QString::number(i));
        this->buttonList.at(i)->setDisabled(true);
        grid->addWidget(this->buttonList.at(i), row, col);

        this->buttonList.at(i)->installEventFilter(parent);

        if(i<5){
            row -= 2;
        }else if(i<10){
            col -=2;
        }
        else if(i<15){
            row +=2 ;
        }
        else if(i<19){
            col +=2;
        }else if(i==19){
            row -= 2;
        }
        else if(i==20){
            row -=6;
        }
        else if(i==21){
            col-=6;
        }
        else if(i==22){
            row+=6;
        }
        else if(i ==23){
            row -=2;
            col +=4;
        }
        else if(i==24){
            row -=2;
        }
        else if(i == 25){
            col -=2;
        }
        else if(i==26){
            row +=2;
        }
        else if(i==27){
            row -=1;
            col +=1;
        }
    }

    QLabel* label[10];
    row = 9;
    col = 10;
    for(int i=0; i<10; i++){
        label[i] = new QLabel();
        grid->addWidget(label[i], row, col);
        if(i<4){
            row -=2;
        }
        else if(i==4){
            row -=1;
            col -=1;
        }
        else if(i<9){
            col -=2;
        }
    }

}

void MainBoard::setButtonStyleSheetAll(QString style){
    for(auto itr = this->buttonList.begin(); itr != this->buttonList.end(); ++itr){
        (*itr)->setStyleSheet(style);
    }
}

void MainBoard::setButtonStyleSheet(int num, QString style){
    this->buttonList[num]->setStyleSheet(style);
}

void MainBoard::setButtonStyleSheet(int num, int teamNum, int malNum, QString style){
    QString imageUrl = ":/img/team" + QString::number(teamNum) + "_" + QString::number(malNum) + ".png";
    QString btnStyle = "image:url(" + imageUrl + ");" + style;
    this->buttonList[num]->setText("");
    this->buttonList[num]->setStyleSheet(btnStyle);
}
