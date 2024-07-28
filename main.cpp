#include "home_window.h"
#include <QApplication>
#include <QTextCodec>
#include "values_used_always.h"
#include <QFontDatabase>

int edit_windows_open;

void init_rule_set_fun(QFile* pos_file)
{

    pos_file->open(QIODevice::Text|QIODevice::ReadWrite);//以读写的方式打开文件，成功返回true，失败返回false
    QList<QString> init_set_rules;
    init_set_rules.append("{:%规则集名%:}默认规则集文件");
    init_set_rules.append("{:%适用主题%:}Volantis");
    init_set_rules.append("{:%以上摘要%:}<!-- more -->");
    init_set_rules.append("{:%html内联框架=%:}<iframe src=\"_链接\" ~$width=\"_宽度\"$~ ~$height=\"_高度\"$~></iframe>");
    init_set_rules.append("{:%下划线%:}{% u _文字 %}");
    init_set_rules.append("{:%着重号%:}{% emp _文字 %}");
    init_set_rules.append("{:%波浪线%:}{% wavy _文字 %}");
    init_set_rules.append("{:%删除%:}{% del _文字 %}");
    init_set_rules.append("{:%键盘文字%:}{% kbd _文字 %}");
    init_set_rules.append("{:%密码%:}{% psw _文字 %}");
    init_set_rules.append("{:%便签块儿%:}{% noteblock ~$_参数参考各类便签$~::~$_标题$~ %}丨_文字丨{% endnoteblock %}");
    init_set_rules.append("{:%便签%:}{% note::_文字 %}");
    init_set_rules.append("{:%引用便签%:}{% note quote::note quote _文字 %}");
    init_set_rules.append("{:%信息便签%:}{% note info::note info _文字 %}");
    init_set_rules.append("{:%警告便签%:}{% note warning::note warning _文字 %}");
    init_set_rules.append("{:%注意危险%:}{% note danger::note danger _文字 %}");
    init_set_rules.append("{:%成功%:}{% note success::note success _文字 %}");
    init_set_rules.append("{:%bug提示%:}{% note bug red::note bug red _文字 %}");
    init_set_rules.append("{:%计划便签%:}{% note todo::note todo _文字 %}");
    init_set_rules.append("{:%引导%:}{% note guide clear::note guide clear _文字 %}");
    init_set_rules.append("{:%下载便签%:}{% note download::note download _文字 %}");
    init_set_rules.append("{:%信息%:}{% note message gray::note message gray _文字 %}");
    init_set_rules.append("{:%更新%:}{% note up::note up _文字 %}");
    init_set_rules.append("{:%撤回%:}{% note undo light::note undo light _文字 %}");
    init_set_rules.append("{:%复选框%:}{% checkbox ~$_颜色$~ ~$checked$~ ::_文字 %}");
    init_set_rules.append("{:%复选框 +%:}{% checkbox plus ~$_颜色$~ checked::_文字 %}");
    init_set_rules.append("{:%复选框 -%:}{% checkbox minus ~$_颜色$~ checked::_文字 %}");
    init_set_rules.append("{:%复选框 X%:}{% checkbox times ~$_颜色$~ checked::_文字 %}");
    init_set_rules.append("{:%单选框%:}{% radio ~$_颜色$~ ~$checked$~ ::_文字 %}");
    init_set_rules.append("{:%行内按钮%:}{% btn _文字:: / %}");
    init_set_rules.append("{:%按钮%:}{% btn regular::_文字::_链接 ~$::fas fa-play-circle$~ %}");
    init_set_rules.append("{:%中央大按钮%:}{% btn center large::_文字::_链接 ~$::fas fa-download$~ %}");
    init_set_rules.append("{:%md式链接=%:}[_名称](_链接 \"_标题\")");
    init_set_rules.append("{:%链接小卡片%:}{% link _标题::_链接 ~$::_IMG_链接$~ %}");
    init_set_rules.append("{:%行内图片%:}{% inlineimage _链接 ~$::height=_高度$~ %}");
    init_set_rules.append("{:%描述性图片%:}{% gallery %}丨![_文字](_链接)丨{% endgallery %}");
    init_set_rules.append("{:%注释性图片%:}{% image _链接 ~$::width=_宽度$~ ~$::height=_高度$~ ::alt=_文字 ~$::bg=_颜色$~ %}");
    init_set_rules.append("{:%AUDIO%:}{% audio _链接 %}");
    init_set_rules.append("{:%VIDEO%:}{% video _链接 %}");
    init_set_rules.append("{:%folding%:}{% folding ~$_颜色$~ ~$open$~ ::_标题 %}丨_文字丨{% endfolding %}");
    init_set_rules.append("{:%Tabs%:}{% tabs _这里随便写点什么，但同一个页面内多个Tab块儿这里的内容不能重复 %}丨<!-- tab _TITLE -->丨_文字丨<!-- endtab -->丨<!-- tab _TITLE -->丨_文字丨<!-- endtab -->丨{% endtabs %}");
    init_set_rules.append("{:%TimeLine%:}{% timeline ~$_时间线标题$~ %}丨{% timenode _标题 %}丨_文字丨{% endtimenode %}丨{% timenode _标题 %}丨_文字丨{% endtimenode %}丨{% endtimeline %}");
    init_set_rules.append("{:%外部.md文件%:}{% md _链接 %}");
    init_set_rules.append("{:%网盘下载%:}{% pandown _网盘类型 :: _链接 ~$::_PSW$~ :: _FILE_名称 %}");
    init_set_rules.append("{:%自定义1%:}");
    init_set_rules.append("{:%自定义2%:}");
    init_set_rules.append("{:%自定义3%:}");
    init_set_rules.append("{:%自定义4%:}");
    init_set_rules.append("{:%自定义5%:}");
    init_set_rules.append("{:%自定义6%:}");
    //写入文件需要字符串为QByteArray格式

    QTextStream out(pos_file);
    for (int i = 0; i < init_set_rules.size(); ++i)
    {
        out << init_set_rules[i] << endl;
    }
    pos_file->close();
}

void rule_set_exit_fun(bool rule_set_exist_bool,QString file_path,int i)
{

    //如果文件不存在
    if(!rule_set_exist_bool)
    {

        QFile pos_file(file_path);
        QMessageBox::warning(NULL,NULL,"未找到规则集文件"+ QString::number(i,10)+",已重新初始化");
        init_rule_set_fun(&pos_file);
    }
    else
    {

    }
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    home_window w;

    //QFontDatabase::addApplicationFont(":/res/fonts/AiWoZheYuWoLaoLong-2.ttf");
    QFontDatabase::addApplicationFont(":/res/fonts/katong.ttf");
    QFontDatabase::addApplicationFont(":/res/fonts/FiraCode-Regular.ttf");

    int fontId = QFontDatabase::addApplicationFont(":/res/fonts/JJ.ttf");
    //int fontId = QFontDatabase::addApplicationFont(":/res/fonts/HYCFS.ttf");
    //int fontId = QFontDatabase::addApplicationFont(":/res/fonts/01TogeGothic-ExtraLight-2.otf");
    //QString fontFamilies = QFontDatabase::applicationFontFamilies(fontId).at(0);
    //qDebug()<<fontFamilies;


    w.setStyleSheet("QPushButton {font-family:zihunqiatongruantangti}");
    w.setStyleSheet("QLabel {font-family:JMH}");
    w.setStyleSheet("QTextEdit {font-family:Fira Code}");

    w.show();


//zihunqiatongruantangti    AaAWZYWLL (Non-Commercial Use)    Fira Code    JMH

    edit_windows_open=0;
    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

    //---------------------------------------------------规则集文件准备

    //
    for(int temp_i=1;temp_i<4;temp_i++)
    {
        QString file_path=QApplication::applicationDirPath()+"/rule_set_"+ QString::number(temp_i,10) +".txt";
        bool rule_set_exist = QFile::exists(file_path);
        rule_set_exit_fun(rule_set_exist,file_path,temp_i);
    }
    return a.exec();
}
