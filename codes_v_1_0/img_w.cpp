#include "img_w.h"
#include "ui_img_w.h"
#include "values_used_always.h"

img_w::img_w(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::img_w)
{
    choose_which=35;
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");
}

img_w::~img_w()
{
    delete ui;
}

void img_w::on_cancel_btn_clicked()
{
    this->close();
}

void img_w::on_img_1_clicked()
{
    sendData(0);
    this->close();
}

void img_w::on_img_2_clicked()
{
    sendData(1);
    this->close();
}

void img_w::on_img_3_clicked()
{
    sendData(2);
    this->close();
}
