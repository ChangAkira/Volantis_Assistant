#ifndef RULE_SET_EDIT_WIDGET_H
#define RULE_SET_EDIT_WIDGET_H

#include <QWidget>

namespace Ui {
class rule_set_edit_widget;
}

class rule_set_edit_widget : public QWidget
{
    Q_OBJECT

public:
    explicit rule_set_edit_widget(QWidget *parent = 0);
    ~rule_set_edit_widget();

private slots:
    void on_back_btn_clicked();

    void on_save_btn_clicked();

private:
    Ui::rule_set_edit_widget *ui;
};

#endif // RULE_SET_EDIT_WIDGET_H
