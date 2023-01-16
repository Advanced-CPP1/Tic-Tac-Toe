#include "notepad.h"
#include "ui_notepad.h"

NotePad::NotePad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotePad)
{
    ui->setupUi(this);
    this->resize(QSize(1100, 700));
    this->setWindowIcon(QIcon(":/imgs/imgs/notepad_icon.ico"));
    ui->align_left_button->setToolTip(QString("Align left"));
    ui->align_right_button->setToolTip(QString("Align right"));
    ui->center_button->setToolTip(QString("Align center"));
    ui->center_button->setToolTip(QString("Center"));
    for (int i = 2; i <= 72; i += 2) {
        ui->comboBox->addItem(QString::number(i));
    }
    ui->comboBox->setCurrentIndex(7);
    ui->lineEdit->setText(QString("16"));
    ui->align_right_2_button->hide();
    ui->bold_button_2->hide();
    ui->center_button_2->hide();
    ui->italic_button_2->hide();
    ui->underline_button_2->hide();
    ui->linethrough_2->hide();
    ui->align_left_button->hide();
}

NotePad::~NotePad()
{
    delete ui;
}


void NotePad::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit->setFont(f);
}

void NotePad::on_comboBox_activated(int index)
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("font-size: ")).append(ui->comboBox->itemText(index)).append("px;\n"));
    ui->lineEdit->setText(QString(ui->comboBox->itemText(index)));
}

void NotePad::on_color_activated(int index)
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("color: ").append(QString(ui->color->itemText(index).append(";\n")))));
    if (ui->color->itemText(index) == QString("More")) {
        QColorDialog dialog {};
        dialog.setWindowIcon(QIcon(":/imgs/imgs/palette-icon.ico"));
        dialog.setWindowTitle(QString("Choose font-color"));
        if (dialog.exec() == QColorDialog::Accepted) {
            ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("color: ").append(QString(dialog.selectedColor().name()).append(";\n"))));
        }
    }
}

void NotePad::on_bold_button_clicked() {
//    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("font-weight: bold;\n")));
    ui->bold_button_2->setStyleSheet(QString("background-color: grey;\n"));
    QTextCursor cursor = ui->textEdit->textCursor();
    if (!cursor.selectedText().isEmpty()) {
        cursor.beginEditBlock();
        QTextCharFormat format;
        format.setFontWeight(700);
        cursor.setCharFormat(format);
        cursor.endEditBlock();
    }
    ui->bold_button->hide();
    ui->bold_button_2->show();
}

void NotePad::on_bold_button_2_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("font-weight: normal;\n")));
    ui->bold_button_2->hide();
    ui->bold_button->show();
}


void NotePad::on_underline_button_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("text-decoration: underline;\n")));
    ui->underline_button_2->setStyleSheet(QString("background-color: grey;\n"));
    ui->underline_button->hide();
    ui->underline_button_2->show();
}


void NotePad::on_underline_button_2_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("text-decoration: none;\n"));
    ui->linethrough_2->setStyleSheet(QString("background-color: none;\n"));
    ui->underline_button_2->hide();
    ui->underline_button->show();
}


void NotePad::on_center_button_clicked()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->align_left_button_2->hide();
    ui->align_left_button->show();
    ui->align_right_2_button->hide();
    ui->align_right_button->show();
    ui->center_button->hide();
    ui->center_button_2->show();
}

void NotePad::on_italic_button_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append(QString("font-style: italic;\n")));
    ui->italic_button_2->setStyleSheet(QString("background-color: grey;\n"));
    ui->italic_button->hide();
    ui->italic_button_2->show();
}


void NotePad::on_italic_button_2_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("font-style: normal;\n"));
    ui->italic_button_2->hide();
    ui->italic_button->show();
}

void NotePad::on_linethrough_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("text-decoration: line-through;\n"));
    ui->linethrough_2->setStyleSheet(QString("background-color: grey;\n"));
    ui->linethrough->hide();
    ui->linethrough_2->show();
}
void NotePad::on_linethrough_2_clicked()
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("text-decoration: none;\n"));
    ui->underline_button_2->setStyleSheet(QString("background-color: none;\n"));
    ui->linethrough_2->hide();
    ui->linethrough->show();
}

void NotePad::on_paste_button_clicked()
{
    ui->textEdit->paste();
}

void NotePad::on_copy_button_clicked()
{
    ui->textEdit->copy();
}

void NotePad::on_cut_button_clicked()
{
    ui->textEdit->cut();
}

void NotePad::on_actionExit_triggered()
{
    this->close();
}

void NotePad::on_lineEdit_textChanged(const QString &arg1)
{
    ui->textEdit->setStyleSheet(QString(ui->textEdit->styleSheet()).append("font-size: ").append(QString(arg1).append("px;\n")));
}

void NotePad::on_case_combo_activated(int index)
{
    std::string case_type = ui->textEdit->toPlainText().toStdString();
    switch (index) {
        case 0:
        std::transform(case_type.begin(), case_type.end(), case_type.begin(), ::tolower);
        ui->textEdit->setText(QString(case_type.c_str()));
        break;
        case 1:
        std::transform(case_type.begin(), case_type.end(), case_type.begin(), ::toupper);
        ui->textEdit->setText(QString(case_type.c_str()));
        break;
        case 2:
        case_type[0] = toupper(case_type[0]);
        std::transform(case_type.begin() + 1, case_type.end(), case_type.begin() + 1, tolower);
        ui->textEdit->setText(QString(case_type.c_str()));
        break;
    }
}

void NotePad::on_align_right_button_clicked()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
    ui->align_left_button_2->hide();
    ui->align_left_button->show();
    ui->center_button_2->hide();
    ui->center_button->show();
    ui->align_right_button->hide();
    ui->align_right_2_button->show();
}

void NotePad::on_align_left_button_clicked()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
    ui->align_right_2_button->hide();
    ui->align_right_button->show();
    ui->center_button_2->hide();
    ui->center_button->show();
    ui->align_left_button->hide();
    ui->align_left_button_2->show();
}
