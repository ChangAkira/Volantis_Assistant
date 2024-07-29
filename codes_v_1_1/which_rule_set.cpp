#include "which_rule_set.h"
#include "ui_which_rule_set.h"
#include "rule_set_edit_widget.h"
#include "values_used_always.h"
#include "edit_w.h"
int editing_which_rule_set;
bool choose_true;

void read_base_information(QFile* file,QString* name,QString* theme)
{
    QRegularExpression re("{:%.*?%:}");
    file->open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(file);
    QString line = in.readLine();      //整行读取
    line.replace(re,"");
    *name=line;
    line = in.readLine();      //整行读取
    line.replace(re,"");
    *theme=line;
    file->close();
}

which_rule_set::which_rule_set(QWidget *parent) :
QWidget(parent),
ui(new Ui::which_rule_set)
{
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");


    if(edit_set_or_edit==2)
    {
        edit_windows_open++;
    }

    QString name;
    QString theme;
    editing_which_rule_set=0;
    QString file_path_part_1=QApplication::applicationDirPath()+"/rule_set_";
    QFile file1(file_path_part_1+"1.txt");
    read_base_information(&file1,&name,&theme);
    ui->rule_set_1->setText("规则集1\n\n\n<规则集名>\n"+name+"\n\n<适用主题>\n"+theme);

    QFile file2(file_path_part_1+"2.txt");
    read_base_information(&file2,&name,&theme);
    ui->rule_set_2->setText("规则集2\n\n\n<规则集名>\n"+name+"\n\n<适用主题>\n"+theme);

    QFile file3(file_path_part_1+"3.txt");
    read_base_information(&file3,&name,&theme);
    ui->rule_set_3->setText("规则集3\n\n\n<规则集名>\n"+name+"\n\n<适用主题>\n"+theme);
}

which_rule_set::~which_rule_set()
{
    delete ui;
}

void which_rule_set::on_back_btn_clicked()
{
    editing_set_true=0;
    if(edit_set_or_edit==2)
    {
        edit_windows_open--;
    }
    editing_which_rule_set=0;
    this->close();
}

void which_rule_set::on_go_btn_clicked()
{
    if(editing_which_rule_set==0||choose_true==0)
    {
        QMessageBox::warning(NULL,NULL,"你还没选择！\n你是笨比吗");
    }
    else
    {
        if (edit_set_or_edit==1)//如果是要打开编辑规则集界面
        {
            if(edit_windows_open!=0)  //有编辑文字界面
            {

                QMessageBox::warning(NULL,NULL,"不要在编辑文字界面打开的情况下编辑规则集哇QAQ！");
            }
            else
            {
                rule_set_edit_widget *w_rule_set_edit_widget=new rule_set_edit_widget();
                w_rule_set_edit_widget->show();
                choose_true=0;
                this->close();
            }
        }
        else if (edit_set_or_edit==2)
        {
            if (editing_set_true)
            {
                QMessageBox::warning(NULL,NULL,"不要在编辑规则集界面打开的情况下编辑文字哇QAQ！");
            }
            else
            {
                edit_w *w_edit_w=new edit_w();
                w_edit_w->show();
                choose_true=0;
                this->close();
            }
        }
    }
}

void which_rule_set::on_rule_set_1_clicked()
{
    editing_which_rule_set=1;
    choose_true=1;
}

void which_rule_set::on_rule_set_2_clicked()
{
    editing_which_rule_set=2;
    choose_true=1;
}

void which_rule_set::on_rule_set_3_clicked()
{
    editing_which_rule_set=3;
    choose_true=1;
}
