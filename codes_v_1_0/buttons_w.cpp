#include "buttons_w.h"
#include "ui_buttons_w.h"
#include "values_used_always.h"

buttons_w::buttons_w(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buttons_w)
{
    choose_which=30;
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");
}

buttons_w::~buttons_w()
{
    delete ui;
}

void buttons_w::on_cancel_btn_clicked()
{
    this->close();
}

void buttons_w::on_btn_1_clicked()
{
    sendData(0);
    this->close();
}

void buttons_w::on_btn_2_clicked()
{
    sendData(1);
    this->close();
}

void buttons_w::on_btn_3_clicked()
{
    sendData(2);
    this->close();
}
