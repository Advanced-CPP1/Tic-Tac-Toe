#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QPixmap>
#include <QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    char player {'X'};
    char grid_1{};
    char grid_2{};
    char grid_3{};
    char grid_4{};
    char grid_5{};
    char grid_6{};
    char grid_7{};
    char grid_8{};
    char grid_9{};
    int player_1_score{};
    int player_2_score{};
    ~TicTacToe();

private slots:
    void on_start_button_clicked();

    void on_grid_1_clicked();

    void on_grid_2_clicked();

    void on_grid_3_clicked();

    void on_grid_4_clicked();

    void on_grid_5_clicked();

    void on_grid_6_clicked();

    void on_grid_7_clicked();

    void on_grid_8_clicked();

    void on_grid_9_clicked();

private:
    Ui::TicTacToe *ui;
};
#endif // TICTACTOE_H
