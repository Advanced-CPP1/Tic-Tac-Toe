#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QColorDialog>
#include <QKeyEvent>
#include <algorithm>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class NotePad; }
QT_END_NAMESPACE

class NotePad : public QMainWindow
{
    Q_OBJECT

public:
    NotePad(QWidget *parent = nullptr);
    ~NotePad();

private slots:
    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_comboBox_activated(int index);

    void on_color_activated(int index);

    void on_bold_button_clicked();

    void on_bold_button_2_clicked();

    void on_underline_button_clicked();

    void on_underline_button_2_clicked();

    void on_center_button_clicked();

    void on_italic_button_clicked();

    void on_italic_button_2_clicked();

    void on_linethrough_clicked();

    void on_linethrough_2_clicked();

    void on_paste_button_clicked();

    void on_copy_button_clicked();

    void on_cut_button_clicked();

    void on_actionExit_triggered();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_case_combo_activated(int index);

    void on_align_right_button_clicked();

    void on_align_left_button_clicked();

private:
    Ui::NotePad *ui;
};
#endif // NOTEPAD_H
