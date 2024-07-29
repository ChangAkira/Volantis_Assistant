#ifndef HOME_WINDOW_H
#define HOME_WINDOW_H

#include <QWidget>

namespace Ui {
class home_window;
}

class home_window : public QWidget
{
    Q_OBJECT

public:
    explicit home_window(QWidget *parent = 0);
    ~home_window();

private slots:
    void on_about_btn_clicked();

    void on_edit_sheet_clicked();

    void on_new_edit_btn_clicked();

private:
    Ui::home_window *ui;
};

#endif // HOME_WINDOW_H
