#ifndef MAINTEAMS_H
#define MAINTEAMS_H

#include <QWidget>
#include <QGridLayout>

#include "yutmodel.h"
class YutController;

class MainTeams : public QWidget
{
    Q_OBJECT
public:
    explicit MainTeams(int teamNum, int malNum, QWidget *parent = nullptr);

signals:
    void sendtoCtrl();

public slots:

private:
    void setTeams();

public:
    QGridLayout* grid;

private:
    QWidget *parent;
    int totalTeamNum;
    int totalMalNum;
};

#endif // MAINTEAMS_H
