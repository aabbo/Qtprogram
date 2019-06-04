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
    explicit SetupDialog(QWidget *parent = nullptr);
    bool GetStartBool();
    ~SetupDialog();

private slots:
    void on_player_slider_valueChanged(int value);

    void on_mal_slider_valueChanged(int value);

    void on_start_button_clicked();

    void on_cancel_button_clicked();

signals:
    void setValueOfTeams(int value);
    void setValueOfMals(int value);

public:
    int numOfTeam =0;
    int numOfMal = 0;

private:
    YutController* yctrl;
    Ui::SetupDialog *ui;
    bool startbool;

};

#endif // SETUPDIALOG_H
