#include "check_box_w.h"
#include "ui_check_box_w.h"
#include "values_used_always.h"

check_box_w::check_box_w(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::check_box_w)
{
    choose_which=25;
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");
}

check_box_w::~check_box_w()
{
    delete ui;
}

void check_box_w::on_cancel_btn_clicked()
{
    this->close();
}

void check_box_w::on_check_box_1_clicked()
{
    sendData(0);
    this->close();
}

void check_box_w::on_check_box_2_clicked()
{
    sendData(1);
    this->close();
}

void check_box_w::on_check_box_3_clicked()
{
    sendData(2);
    this->close();
}

void check_box_w::on_check_box_4_clicked()
{
    sendData(3);
    this->close();
}
