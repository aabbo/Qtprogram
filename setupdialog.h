#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include <QObject>
#include "ui_setupdialog.h"
class YutController;

namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupDialog(QWidget *parent = nullptr, YutController* ctrl=nullptr);
    bool GetStartBool();
    ~SetupDialog();

private slots:
    void on_player_slider_valueChanged(int value);

    void on_mal_slider_valueChanged(int value);

    void on_start_button_clicked();

    void on_cancel_button_clicked();

    void on_SetupDialog_rejected();

signals:
    void setValueOfTeams(int value);
    void setValueOfMals(int value);
public:
    int totalTeamNum;
    int totalMalNum;
private:
    YutController* yctrl;
    Ui::SetupDialog *ui;
    bool startbool;
    bool startBtnClicked;

};

#endif // SETUPDIALOG_H
