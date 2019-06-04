#ifndef MAINTEAMS_H
#define MAINTEAMS_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QVector>

#include "yutmodel.h"
class YutController;

class MainTeams : public QWidget
{
    Q_OBJECT
public:
    explicit MainTeams(int teamNum, QWidget *parent = nullptr);

signals:
    void sendtoCtrl();

public:
    void setButtonStyleSheetAll(QString style, int totalTeamNum, int totalMalNum, QVector<int> remainMalNum, QVector<int> outtedMalNum);
    void setLabelStyleSheet(int teamNum, QString style);

private:
    void setTeams(int totalTeamNum);

public:
    QGridLayout* grid;

private:
    QWidget *parent;
    QVector<QVector<QPushButton*> > MalButtonList;
    QVector<QLabel*> teamLabelList;
};

#endif // MAINTEAMS_H
