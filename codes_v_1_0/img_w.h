#ifndef IMG_W_H
#define IMG_W_H

#include <QWidget>

namespace Ui {
class img_w;
}

class img_w : public QWidget
{
    Q_OBJECT

public:
    explicit img_w(QWidget *parent = 0);
    ~img_w();

private slots:
    void on_cancel_btn_clicked();

    void on_img_2_clicked();

    void on_img_1_clicked();

    void on_img_3_clicked();

private:
    Ui::img_w *ui;

signals:
    void sendData(int);
};

#endif // IMG_W_H
