#ifndef MAINTEAMS_H
#define MAINTEAMS_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include "yutmodel.h"
class YutController;

class MainTeams : public QWidget
{
    Q_OBJECT
public:
    explicit MainTeams(YutModel* model, YutController* ctrl,QWidget *parent = nullptr);

signals:
    void sendtoCtrl();

public slots:

private:
    void setTeams();

public:
    QGridLayout* grid;
    QVector<QLabel*> labelInfo;

    void setCurrentTeam(int num);

private:
    QWidget* parent;
    YutModel* ymodel;
    YutController* yctrl;
};

#endif // MAINTEAMS_H
