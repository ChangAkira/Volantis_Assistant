#ifndef EDIT_W_H
#define EDIT_W_H

#include <QWidget>

namespace Ui {
class edit_w;
}

class edit_w : public QWidget
{
    Q_OBJECT

public:
    explicit edit_w(QWidget *parent = 0);
    ~edit_w();

private slots:
    void on_back_btn_clicked();

    void on_summary_btn_clicked();

    void on_frame_btn_clicked();

    void on_md_btn_clicked();

    void on_viedo_btn_clicked();

    void on_audio_btn_clicked();

    void on_folding_btn_clicked();

    void on_text_style_btn_clicked();

    void appendData(int which);

    void on_note_block_btn_clicked();

    void on_note_btn_clicked();

    void on_check_box_btn_clicked();

    void on_ratio_btn_clicked();

    void on_btn_btn_clicked();

    void on_url_btn_clicked();

    void on_img_btn_clicked();

    void on_tabs_btn_clicked();

    void on_timeline_btn_clicked();

    void on_pandown_btn_clicked();

    void on_self_defined_1_btn_clicked();

    void on_self_defined_2_btn_clicked();

    void on_self_defined_3_btn_clicked();

    void on_self_defined_4_btn_clicked();

    void on_self_defined_5_btn_clicked();

    void on_self_defined_6_btn_clicked();

private:
    Ui::edit_w *ui;
};

#endif // EDIT_W_H
