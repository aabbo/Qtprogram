#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>

class YutController;

namespace Ui {
class ResultDialog;
}

class ResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResultDialog(int winningTeam, YutController *yctrl, QWidget *parent = nullptr);
    ~ResultDialog();

private slots:
    void on_end_button_clicked();

    void on_restart_button_clicked();

    void on_ResultDialog_rejected();

private:
    Ui::ResultDialog *ui;
    int winningTeam;
    YutController* yctrl;
    bool restartBtnClicked;
};

#endif // RESULTDIALOG_H
