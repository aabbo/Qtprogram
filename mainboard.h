#ifndef MAINBOARD_H
#define MAINBOARD_H

#include "boardbutton.h"
#include <vector>
#include <QGridLayout>

using namespace std;

class MainBoard
{
public:
    MainBoard();

public:
    QGridLayout* grid;
    vector<BoardButton*> buttonList;
    // 26 : 28, 24 방향으로만 가능(0,0)
    // 25 : 28, 27 방향으로만 가능(0,1)
    int recentButton;
};

#endif // MAINBOARD_H
