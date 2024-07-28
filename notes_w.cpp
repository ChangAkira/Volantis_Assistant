#include "notes_w.h"
#include "ui_notes_w.h"
#include "values_used_always.h"

note_block_w::note_block_w(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::note_block_w)
{
    choose_which=12;
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");
}

note_block_w::~note_block_w()
{
    delete ui;
}

void note_block_w::on_cancel_btn_clicked()
{
    this->close();
}

void note_block_w::on_note_1_clicked()
{
    sendData(0);
    this->close();
}

void note_block_w::on_note_2_clicked()
{
    sendData(1);
    this->close();
}

void note_block_w::on_note_3_clicked()
{
    sendData(2);
    this->close();
}

void note_block_w::on_note_4_clicked()
{
    sendData(3);
    this->close();
}

void note_block_w::on_note_5_clicked()
{
    sendData(4);
    this->close();
}

void note_block_w::on_note_6_clicked()
{
    sendData(5);
    this->close();
}

void note_block_w::on_note_7_clicked()
{
    sendData(6);
    this->close();
}

void note_block_w::on_note_8_clicked()
{
    sendData(7);
    this->close();
}

void note_block_w::on_note_9_clicked()
{
    sendData(8);
    this->close();
}

void note_block_w::on_note_10_clicked()
{
    sendData(9);
    this->close();
}

void note_block_w::on_note_11_clicked()
{
    sendData(10);
    this->close();
}

void note_block_w::on_note_12_clicked()
{
    sendData(11);
    this->close();
}

void note_block_w::on_note_13_clicked()
{
    sendData(12);
    this->close();
}
