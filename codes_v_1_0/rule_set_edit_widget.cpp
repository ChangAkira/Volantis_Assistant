#include "rule_set_edit_widget.h"
#include "ui_rule_set_edit_widget.h"
#include "values_used_always.h"
#include <QList>


rule_set_edit_widget::rule_set_edit_widget(QWidget *parent) :
QWidget(parent),
ui(new Ui::rule_set_edit_widget)
{
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");

    this->ui->rule_set_which_label->setText("规则集"+QString::number(editing_which_rule_set));

    QList<QString> lines;
    QRegularExpression re("{:%.*?%:}");
    QString file_path_part_1=QApplication::applicationDirPath()+"/rule_set_";


    QFile file(file_path_part_1+QString::number(editing_which_rule_set)+".txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);


    while (!in.atEnd())
    {
        QString line = in.readLine();
        line.replace(re,"");
        lines.append(line);
    }
    file.close();

    for (int i = 0; i < lines.size(); ++i)
    {
        QString lineEditName = QString("e_value_%1").arg(i + 1); // 生成QLineEdit的名称
        QLineEdit *lineEdit = this->window()->findChild<QLineEdit *>(lineEditName);
        if (lineEdit)
        {
            lineEdit->setText(lines[i]);
            lineEdit->setStyleSheet("font-family:JMH; font-size:24pt; border: 3px solid #ffaaa5; border-radius: 6px; color: #5e63b6;background: transparent;selection-background-color: #a393eb;");
        }
        else
        {
            qDebug() << "No QLineEdit found with name:" << lineEditName;
        }
    }

}

rule_set_edit_widget::~rule_set_edit_widget()
{
    delete ui;
}

void rule_set_edit_widget::on_back_btn_clicked()
{
    editing_set_true=0;
    this->close();
}

void rule_set_edit_widget::on_save_btn_clicked()
{
    QList<QString> lines;
    QRegularExpression re("{:%.*?%:}");
    QString file_path_part_1=QApplication::applicationDirPath()+"/rule_set_";
    QFile file(file_path_part_1+QString::number(editing_which_rule_set)+".txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        lines.append(line);
    }
    file.close();
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
    QTextStream out(&file);
    for (int i = 0; i < lines.size(); ++i)
    {
        QString lineEditName = QString("e_value_%1").arg(i + 1); // 生成QLineEdit的名称
        QLineEdit *lineEdit = this->window()->findChild<QLineEdit *>(lineEditName);
        QRegularExpressionMatch match = re.match(lines[i]);
        if (match.hasMatch())
        {
            QString wrappedPart = match.captured(0);
            QString newString = wrappedPart+lineEdit->text();
            out << newString << "\n";
        }
    }
    file.close();
    editing_set_true=0;
    this->close();
}
