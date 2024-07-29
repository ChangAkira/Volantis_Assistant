#ifndef CHECK_BOX_W_H
#define CHECK_BOX_W_H

#include <QWidget>

namespace Ui {
class check_box_w;
}

class check_box_w : public QWidget
{
    Q_OBJECT

public:
    explicit check_box_w(QWidget *parent = 0);
    ~check_box_w();

private slots:
    void on_cancel_btn_clicked();

    void on_check_box_1_clicked();

    void on_check_box_2_clicked();

    void on_check_box_3_clicked();

    void on_check_box_4_clicked();

private:
    Ui::check_box_w *ui;

signals:
    void sendData(int);
};

#endif // CHECK_BOX_W_H
