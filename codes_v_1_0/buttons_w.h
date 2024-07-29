#ifndef BUTTONS_W_H
#define BUTTONS_W_H

#include <QWidget>

namespace Ui {
class buttons_w;
}

class buttons_w : public QWidget
{
    Q_OBJECT

public:
    explicit buttons_w(QWidget *parent = 0);
    ~buttons_w();

private slots:
    void on_cancel_btn_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

private:
    Ui::buttons_w *ui;

signals:
    void sendData(int);
};

#endif // BUTTONS_W_H
