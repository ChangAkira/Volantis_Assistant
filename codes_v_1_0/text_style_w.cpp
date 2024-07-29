#include "text_style_w.h"
#include "ui_text_style_w.h"
#include "values_used_always.h"



text_style_w::text_style_w(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::text_style_w)
{
    choose_which=5;
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");
}

text_style_w::~text_style_w()
{
    delete ui;
}

void text_style_w::on_cancle_btn_clicked()
{
    this->close();
}

void text_style_w::on_underline_btn_clicked()
{
    sendData(0);
    this->close();
}

void text_style_w::on_emp_btn_clicked()
{
    sendData(1);
    this->close();
}

void text_style_w::on_wavy_btn_clicked()
{
    sendData(2);
    this->close();
}

void text_style_w::on_del_btn_clicked()
{
    sendData(3);
    this->close();
}

void text_style_w::on_keyboard_btn_clicked()
{
    sendData(4);
    this->close();
}

void text_style_w::on_psw_btn_clicked()
{
    sendData(5);
    this->close();
}
