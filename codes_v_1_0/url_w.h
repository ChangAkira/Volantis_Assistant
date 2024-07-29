#ifndef URL_W_H
#define URL_W_H

#include <QWidget>

namespace Ui {
class url_w;
}

class url_w : public QWidget
{
    Q_OBJECT

public:
    explicit url_w(QWidget *parent = 0);
    ~url_w();

private slots:
    void on_cancel_btn_clicked();

    void on_url_1_clicked();

    void on_url_2_clicked();

private:
    Ui::url_w *ui;

signals:
    void sendData(int);
};

#endif // URL_W_H
