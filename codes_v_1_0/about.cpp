#include "about.h"
#include "ui_about.h"
#include <QDesktopServices>
#include <QUrl>
#include "values_used_always.h"

about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->ui->avatar_label->setPixmap(QPixmap(":/res/fonts/avatar.jpg"));
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");
}

about::~about()
{
    delete ui;
}

void about::on_blog_btn_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://changakira.github.io/")));
}

void about::on_email_btn_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("mailto:a259759666@163.com")));
}

void about::on_back_btn_clicked()
{
    this->close();
}

void about::on_github_btn_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/ChangAkira/Volantis_Assistant")));
}
