#ifndef NOTE_BLOCK_W_H
#define NOTE_BLOCK_W_H

#include <QWidget>

namespace Ui {
class note_block_w;
}

class note_block_w : public QWidget
{
    Q_OBJECT

public:
    explicit note_block_w(QWidget *parent = 0);
    ~note_block_w();

private:
    Ui::note_block_w *ui;

signals:
    void sendData(int);

private slots:
    void on_cancel_btn_clicked();
    void on_note_1_clicked();
    void on_note_2_clicked();
    void on_note_3_clicked();
    void on_note_4_clicked();
    void on_note_5_clicked();
    void on_note_6_clicked();
    void on_note_7_clicked();
    void on_note_8_clicked();
    void on_note_9_clicked();
    void on_note_10_clicked();
    void on_note_11_clicked();
    void on_note_12_clicked();
    void on_note_13_clicked();
};

#endif // NOTE_BLOCK_W_H
