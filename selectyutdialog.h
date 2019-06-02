#ifndef SELECTYUTDIALOG_H
#define SELECTYUTDIALOG_H

#include <QDialog>

namespace Ui {
class SelectYutDialog;
}

class SelectYutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectYutDialog(QWidget *parent = nullptr);
    ~SelectYutDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_radio0_BB_do_clicked();

    void on_radio1_do_clicked();

    void on_radio2_gae_clicked();

    void on_radio3_gul_clicked();

    void on_radio4_yut_clicked();

    void on_radio5_mo_clicked();

 public:
    int yut;
    bool status;
private:
    Ui::SelectYutDialog *ui;
};

#endif // SELECTYUTDIALOG_H
