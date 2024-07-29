#ifndef TEXT_STYLE_W_H
#define TEXT_STYLE_W_H

#include <QWidget>

namespace Ui {
class text_style_w;
}

class text_style_w : public QWidget
{
    Q_OBJECT

public:
    explicit text_style_w(QWidget *parent = 0);
    ~text_style_w();

private slots:
    void on_cancle_btn_clicked();

    void on_underline_btn_clicked();

    void on_emp_btn_clicked();

    void on_wavy_btn_clicked();

    void on_del_btn_clicked();

    void on_keyboard_btn_clicked();

    void on_psw_btn_clicked();
signals:
    void sendData(int);

private:
    Ui::text_style_w *ui;
};





#endif // TEXT_STYLE_W_H
