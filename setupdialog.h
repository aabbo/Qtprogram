#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>

namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupDialog(QWidget *parent = nullptr);
    ~SetupDialog();

private slots:
    void on_player_slider_valueChanged(int value);

    void on_mal_slider_valueChanged(int value);

    void on_start_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::SetupDialog *ui;
    int playerNum;
    int malNum;

public:
    bool startbool;
};

#endif // SETUPDIALOG_H
