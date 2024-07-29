#include "home_window.h"
#include "ui_home_window.h"
#include "about.h"
#include "which_rule_set.h"
#include "values_used_always.h"

int edit_set_or_edit=0;
bool editing_set_true;

home_window::home_window(QWidget *parent) :
QWidget(parent),
ui(new Ui::home_window)
{
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");

    edit_windows_open=0;
}

home_window::~home_window()
{
    delete ui;
}

void home_window::on_about_btn_clicked()
{
    about *w_about=new about();
    w_about->show();
}

void home_window::on_edit_sheet_clicked()
{
    if(editing_set_true)
    {
        QMessageBox::warning(NULL,NULL,"不要同时打开两个编辑规则集页面哇QAQ！");
    }
    else
    {
        if(edit_windows_open!=0)
        {
            QMessageBox::warning(NULL,NULL,"不要在编辑文字界面打开的情况下编辑规则集哇QAQ！");
        }
        else
        {
            editing_set_true=1;
            edit_set_or_edit=1;
            which_rule_set *w_which_rule_set=new which_rule_set();
            w_which_rule_set->show();
        }
    }
}

void home_window::on_new_edit_btn_clicked()
{
    if(editing_set_true)
    {
        QMessageBox::warning(NULL,NULL,"不要在编辑规则集界面打开的情况下编辑文字哇QAQ！");
    }
    else
    {
        edit_set_or_edit=2;
        which_rule_set *w_which_rule_set=new which_rule_set();
        w_which_rule_set->show();
    }
}
