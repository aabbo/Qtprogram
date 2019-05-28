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

public slots:

public:
    // 현재 위치 말 정보
    int num;
    vector<QPushButton*> nextStep;
    vector<QPushButton*> prevStep;
};

#endif // BOARDBUTTON_H
