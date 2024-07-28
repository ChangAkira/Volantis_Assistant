#include "url_w.h"
#include "ui_url_w.h"
#include "values_used_always.h"

url_w::url_w(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::url_w)
{
    choose_which=33;
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");
}

url_w::~url_w()
{
    delete ui;
}

void url_w::on_cancel_btn_clicked()
{
    this->close();
}

void url_w::on_url_1_clicked()
{
    sendData(0);
    this->close();
}

void url_w::on_url_2_clicked()
{
    sendData(1);
    this->close();
}
