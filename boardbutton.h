#ifndef BOARDBUTTON_H
#define BOARDBUTTON_H

#include <QPushButton>
#include <QVector>

class BoardButton
{
public:
    explicit BoardButton(int num);

public:
    // 현재 위치 말 정보
    const int num;
    QVector<BoardButton*> nextStep;
    QVector<BoardButton*> prevStep;
    int mals; //num of mal
    int team; //whoes mal is in here
};

#endif // BOARDBUTTON_H
