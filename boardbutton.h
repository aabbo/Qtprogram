#ifndef BOARDBUTTON_H
#define BOARDBUTTON_H

#include <QWidget>
#include <QPushButton>

#include <vector>

using namespace std;

class BoardButton : public QPushButton
{
    Q_OBJECT
public:
    explicit BoardButton(QWidget *parent = nullptr);

signals:
    void clicked(QPushButton* btn);
public slots:
    void click();
public:
    // 현재 위치 말 정보
    int num;
    vector<QPushButton*> nextStep;
    vector<QPushButton*> prevStep;
    int mals; //num of mal
    int team; //whoes mal is in here
};

#endif // BOARDBUTTON_H
