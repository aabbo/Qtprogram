#ifndef MAINTEAMS_H
#define MAINTEAMS_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QVector>

class MainTeams : public QWidget
{
    Q_OBJECT
public:
    explicit MainTeams(int teamNum, int malNum, QWidget *parent = nullptr);

public:
    void setButtonStyleSheetAll(QString style, int totalTeamNum, QVector<int> remainMalNum, QVector<int> outtedMalNum);
    void setButtonStyle(QString style, int teamNum, int remainedMalNum);
    void setLabelStyleSheet(int teamNum, QString style);
    void setButtonEnable(int teamNum, int remainedMalNum);
    void setButtonDisable(int teamNum, int remainedMalNum);

private:
    void setTeams(int totalTeamNum, int totalMalNum);

public:
    QGridLayout* mal;
    QGridLayout* result;

private:
    QWidget *parent;
    QVector<QVector<QPushButton*> > MalButtonList;
    QVector<QLabel*> teamLabelList;
    QVector<QLabel*> resutlLabelList;


};

#endif // MAINTEAMS_H
