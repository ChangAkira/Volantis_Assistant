#include "edit_w.h"
#include "ui_edit_w.h"
#include "values_used_always.h"
#include "with_menus.h"

QList<QString> lines;
int choose_which;
int line_count;

void text_insert_fun(Ui::edit_w *dis,int line_count)
{
    QStringList temp_lines = lines[line_count-1].split("丨");
    for(int i=0;i<temp_lines.size();i++)
    {
        dis->textEdit->insertPlainText("\n\n"+temp_lines[i]);
    }
    dis->textEdit->insertPlainText("\n\n");
    dis->textEdit->moveCursor(QTextCursor::End);
    dis->textEdit->setFocus();
}

void edit_w::appendData(int which)  //有二级菜单的需要使用
{
    text_insert_fun(ui,choose_which+which);
}

edit_w::edit_w(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edit_w)
{
    ui->setupUi(this);
    this->setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    this->setStyleSheet("QLabel {font-family:JMH}");
    this->setStyleSheet("QTextEdit {font-family:Fira Code}}");

    ui->textEdit->setPlaceholderText("在此输入...\ntips:\n在打开的主页窗口可再打开一个编辑窗口\n请使用复制粘贴");
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
    ui->textEdit->setFocus();
}

edit_w::~edit_w()
{
    delete ui;
}

void edit_w::on_back_btn_clicked()  //返回
{
    edit_windows_open--;
    if(edit_windows_open==0)
    {
        edit_set_or_edit=0;
    }
    this->close();
}

void edit_w::on_summary_btn_clicked()  //摘要
{
    line_count=3;
    text_insert_fun(ui,line_count);
}

void edit_w::on_frame_btn_clicked()  //内联框架
{
    line_count=4;
    text_insert_fun(ui,line_count);
}

void edit_w::on_text_style_btn_clicked()  //文字样式，二级菜单
{
    text_style_w *w_t_s=new text_style_w();
    connect(w_t_s,SIGNAL(sendData(int)),this,SLOT(appendData(int)));
    w_t_s->show();
}

void edit_w::on_note_block_btn_clicked()  //note_block
{
    line_count=11;
    text_insert_fun(ui,line_count);
}

void edit_w::on_note_btn_clicked()  //note，二级菜单
{
    note_block_w *w_notes = new note_block_w();
    connect(w_notes,SIGNAL(sendData(int)),this,SLOT(appendData(int)));
    w_notes->show();
}

void edit_w::on_check_box_btn_clicked()  //复选框，二级菜单
{
    check_box_w *w_check_box = new check_box_w();
    connect(w_check_box,SIGNAL(sendData(int)),this,SLOT(appendData(int)));
    w_check_box->show();
}

void edit_w::on_ratio_btn_clicked()  //单选框
{
    line_count=29;
    text_insert_fun(ui,line_count);
}

void edit_w::on_btn_btn_clicked()  //按钮，二级菜单
{
    buttons_w *w_buttons = new buttons_w();
    connect(w_buttons,SIGNAL(sendData(int)),this,SLOT(appendData(int)));
    w_buttons->show();
}

void edit_w::on_url_btn_clicked()  //url,二级菜单
{
    url_w *w_url =new url_w();
    connect(w_url,SIGNAL(sendData(int)),this,SLOT(appendData(int)));
    w_url->show();
}

void edit_w::on_img_btn_clicked()  //img，二级菜单
{
    img_w *w_img = new img_w();
    connect(w_img,SIGNAL(sendData(int)),this,SLOT(appendData(int)));
    w_img->show();
}

void edit_w::on_audio_btn_clicked()  //AUDIO
{
    line_count=38;
    text_insert_fun(ui,line_count);
}

void edit_w::on_viedo_btn_clicked()  //VIEDO
{
    line_count=39;
    text_insert_fun(ui,line_count);
}

void edit_w::on_folding_btn_clicked()  //folding
{
    line_count=40;
    text_insert_fun(ui,line_count);
}

void edit_w::on_tabs_btn_clicked()  //tabs
{
    line_count=41;
    text_insert_fun(ui,line_count);
}

void edit_w::on_timeline_btn_clicked()  //timeline
{
    line_count=42;
    text_insert_fun(ui,line_count);
}

void edit_w::on_md_btn_clicked()  //外部.md
{
    line_count=43;
    text_insert_fun(ui,line_count);
}

void edit_w::on_pandown_btn_clicked()  //盘下载
{
    line_count=44;
    text_insert_fun(ui,line_count);
}

void edit_w::on_self_defined_1_btn_clicked()  //自定义1
{
    line_count=45;
    text_insert_fun(ui,line_count);
}

void edit_w::on_self_defined_2_btn_clicked()  //自定义2
{
    line_count=46;
    text_insert_fun(ui,line_count);
}

void edit_w::on_self_defined_3_btn_clicked()  //自定义3
{
    line_count=47;
    text_insert_fun(ui,line_count);
}

void edit_w::on_self_defined_4_btn_clicked()  //自定义4
{
    line_count=48;
    text_insert_fun(ui,line_count);
}

void edit_w::on_self_defined_5_btn_clicked()  //自定义5
{
    line_count=49;
    text_insert_fun(ui,line_count);
}

void edit_w::on_self_defined_6_btn_clicked()  //自定义6
{
    line_count=50;
    text_insert_fun(ui,line_count);
}
