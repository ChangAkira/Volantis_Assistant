#ifndef WHICH_RULE_SET_H
#define WHICH_RULE_SET_H

#include <QWidget>

namespace Ui {
class which_rule_set;
}

class which_rule_set : public QWidget
{
    Q_OBJECT

public:
    explicit which_rule_set(QWidget *parent = 0);
    ~which_rule_set();

private slots:
    void on_back_btn_clicked();

    void on_go_btn_clicked();

    void on_rule_set_1_clicked();

    void on_rule_set_2_clicked();

    void on_rule_set_3_clicked();

private:
    Ui::which_rule_set *ui;
};

#endif // WHICH_RULE_SET_H
