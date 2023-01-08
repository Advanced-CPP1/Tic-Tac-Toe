#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <QPropertyAnimation>

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(900, 600));
    this->setWindowIcon(QIcon(":/media/tic-tac-toe_icon.ico"));
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    player->setSource(QUrl::fromLocalFile("qrc:/media/game_music.mp3"));
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(30);
    player->play();
    ui->game_grid->hide();
    ui->player_1_score->setAlignment(Qt::AlignCenter);
    ui->player_2_score->setAlignment(Qt::AlignCenter);
    ui->winner_label->setAlignment(Qt::AlignCenter);
    ui->straight_line->hide();
    ui->straight_line_2->hide();
    ui->straight_line_3->hide();
    ui->straight_line_4->hide();
    ui->straight_line_5->hide();
    ui->straight_line_6->hide();
    ui->straight_line_7->hide();
    ui->straight_line_8->hide();
    ui->straight_line_9->hide();
    ui->pushButton->hide();
    ui->grid_1->hide();
    ui->grid_2->hide();
    ui->grid_3->hide();
    ui->grid_4->hide();
    ui->grid_5->hide();
    ui->grid_6->hide();
    ui->grid_7->hide();
    ui->grid_8->hide();
    ui->grid_9->hide();
    ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::on_start_button_clicked()
{
    this->setStyleSheet(QString("background-color: #14bdac;\n"));
    ui->game_grid->show();
    ui->grid_1->show();
    ui->grid_2->show();
    ui->grid_3->show();
    ui->grid_4->show();
    ui->grid_5->show();
    ui->grid_6->show();
    ui->grid_7->show();
    ui->grid_8->show();
    ui->grid_9->show();
    QPixmap *game_grid = new QPixmap(":/media/game_grid.png");
    ui->game_grid->setPixmap(game_grid->scaled(ui->game_grid->width(), ui->game_grid->height(), Qt::KeepAspectRatio));
    ui->game_grid->setAlignment(Qt::AlignCenter);
    ui->start_button->hide();
}

void TicTacToe::on_grid_1_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_1->icon().isNull()) {
            ui->grid_1->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_1->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_1 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_1->icon().isNull()) {
            ui->grid_1->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_1->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_1 = 'O';
            player = 'X';
        }
    }

     /* Separator */

     if (grid_2 == grid_1 && grid_3 == grid_1) {
         ui->straight_line->show();
         ui->pushButton->show();
         QMediaPlayer *success = new QMediaPlayer;
         QAudioOutput *AudioOutput = new QAudioOutput;
         success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
         success->setAudioOutput(AudioOutput);
         AudioOutput->setVolume(75);
         success->play();
         if (grid_1 == 'X') {
             player_1_score += 1;
             ui->player_1_score->setText(QString::number(player_1_score));
             ui->winner_label->setText(QString("Player 1 wins!"));
         }
         else if (grid_1 == 'O') {
             player_2_score += 1;
             ui->player_2_score->setText(QString::number(player_2_score));
             ui->winner_label->setText(QString("Player 2 wins!"));
         }
     }

     else if (grid_4 == grid_1 && grid_7 == grid_1) {
         ui->straight_line_2->show();
         ui->pushButton->show();
         QMediaPlayer *success = new QMediaPlayer;
         QAudioOutput *AudioOutput = new QAudioOutput;
         success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
         success->setAudioOutput(AudioOutput);
         AudioOutput->setVolume(75);
         success->play();
         if (grid_1 == 'X') {
             player_1_score += 1;
             ui->player_1_score->setText(QString::number(player_1_score));
             ui->winner_label->setText(QString("Player 1 wins!"));
         }
         else if (grid_1 == 'O') {
             player_2_score += 1;
             ui->player_2_score->setText(QString::number(player_2_score));
             ui->winner_label->setText(QString("Player 2 wins!"));
         }
     }

     else if (grid_5 == grid_1 && grid_9 == grid_1) {
         ui->straight_line_3->show();
         ui->pushButton->show();
         QMediaPlayer *success = new QMediaPlayer;
         QAudioOutput *AudioOutput = new QAudioOutput;
         success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
         success->setAudioOutput(AudioOutput);
         AudioOutput->setVolume(75);
         success->play();
         if (grid_1 == 'X') {
             player_1_score += 1;
             ui->player_1_score->setText(QString::number(player_1_score));
             ui->winner_label->setText(QString("Player 1 wins!"));
         }
         else if (grid_1 == 'O') {
             player_2_score += 1;
             ui->player_2_score->setText(QString::number(player_2_score));
             ui->winner_label->setText(QString("Player 2 wins!"));
         }
     }

     /* End of separator */

}


void TicTacToe::on_grid_2_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_2->icon().isNull()) {
            ui->grid_2->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_2->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_2 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_2->icon().isNull()) {
            ui->grid_2->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_2->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_2 = 'O';
            player = 'X';
        }
    }

    /* Separator */

    if (grid_5 == grid_2 && grid_8 == grid_2) {
        ui->straight_line_4->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_2 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_2 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_1 == grid_2 && grid_3 == grid_2) {
        ui->straight_line->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_2 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_2 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    /* End of separator */

}


void TicTacToe::on_grid_3_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_3->icon().isNull()) {
            ui->grid_3->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_3->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_3 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_3->icon().isNull()) {
            ui->grid_3->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_3->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_3 = 'O';
            player = 'X';
        }
    }

    /* Separator */

    if (grid_6 == grid_3 && grid_9 == grid_3) {
        ui->straight_line_5->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_3 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_3 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_2 == grid_3 && grid_1 == grid_3) {
        ui->straight_line->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_3 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_3 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_5 == grid_3 && grid_7 == grid_3) {
        ui->straight_line_6->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_3 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_3 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    /* End of separator */

}

void TicTacToe::on_grid_4_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_4->icon().isNull()) {
            ui->grid_4->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_4->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_4 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_4->icon().isNull()) {
            ui->grid_4->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_4->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_4 = 'O';
            player = 'X';
        }
    }

    /* Separator */

    if (grid_1 == grid_4 && grid_7 == grid_4) {
        ui->straight_line_2->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_4 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_4 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_5 == grid_4 && grid_6 == grid_4) {
        ui->straight_line_7->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_4 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_4 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    /* End of separator */

}


void TicTacToe::on_grid_5_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_5->icon().isNull()) {
            ui->grid_5->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_5->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_5 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_5->icon().isNull()) {
            ui->grid_5->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_5->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_5 = 'O';
            player = 'X';
        }
    }

    if (grid_4 == grid_5 && grid_6 == grid_5) {
        ui->straight_line_7->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_5 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_5 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_2 == grid_5 && grid_8 == grid_5) {
        ui->straight_line_4->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_5 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_5 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_3 == grid_5 && grid_7 == grid_5) {
        ui->straight_line_6->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_5 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_5 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_1 == grid_5 && grid_9 == grid_5) {
        ui->straight_line_3->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_5 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_5 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

}


void TicTacToe::on_grid_6_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_6->icon().isNull()) {
            ui->grid_6->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_6->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_6 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_6->icon().isNull()) {
            ui->grid_6->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_6->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_6 = 'O';
            player = 'X';
        }
    }

    if (grid_3 == grid_6 && grid_9 == grid_6) {
        ui->straight_line_5->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_6 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_6 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_4 == grid_6 && grid_5 == grid_6) {
        ui->straight_line_7->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_6 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_6 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

}


void TicTacToe::on_grid_7_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_7->icon().isNull()) {
            ui->grid_7->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_7->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_7 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_7->icon().isNull()) {
            ui->grid_7->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_7->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_7 = 'O';
            player = 'X';
        }
    }

    if (grid_1 == grid_7 && grid_4 == grid_7) {
        ui->straight_line_2->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_7 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_7 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_8 == grid_7 && grid_9 == grid_7) {
        ui->straight_line_8->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_7 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_7 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_3 == grid_7 && grid_5 == grid_7) {
        ui->straight_line_6->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_7 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_7 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }
}


void TicTacToe::on_grid_8_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_8->icon().isNull()) {
            ui->grid_8->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_8->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_8 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_8->icon().isNull()) {
            ui->grid_8->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_8->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_8 = 'O';
            player = 'X';
        }
    }

    if (grid_2 == grid_8 && grid_5 == grid_8) {
        ui->straight_line_4->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_8 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_8 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_7 == grid_8 && grid_9 == grid_8) {
        ui->straight_line_8->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_8 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_8 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }
}


void TicTacToe::on_grid_9_clicked()
{
    QMediaPlayer *click = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    click->setSource(QUrl::fromLocalFile("qrc:/media/game_click.mp3"));
    click->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    click->play();
    if (player == 'X') {
        if (ui->grid_9->icon().isNull()) {
            ui->grid_9->setIcon(QIcon(":/media/x_icon.png"));
            ui->grid_9->setIconSize(QSize(100, 100));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_2->setStyleSheet(ui->player_2->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_9 = 'X';
            player = 'O';
        }
    }

    else if (player == 'O') {
        if (ui->grid_9->icon().isNull()) {
            ui->grid_9->setIcon(QIcon(":/media/o_icon.png"));
            ui->grid_9->setIconSize(QSize(100, 100));
            ui->player_2->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: none; font-weight: normal;\n")));
            ui->player_1->setStyleSheet(ui->player_1->styleSheet().append(QString("text-decoration: underline; font-weight: 900;\n")));
            grid_9 = 'O';
            player = 'X';
        }
    }

    if (grid_1 == grid_9 && grid_5 == grid_9) {
        ui->straight_line_3->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_9 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_9 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_3 == grid_9 && grid_6 == grid_9) {
        ui->straight_line_9->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_9 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_9 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }

    else if (grid_7 == grid_9 && grid_8 == grid_9) {
        ui->straight_line_8->show();
        ui->pushButton->show();
        QMediaPlayer *success = new QMediaPlayer;
        QAudioOutput *AudioOutput = new QAudioOutput;
        success->setSource(QUrl::fromLocalFile("qrc:/media/success.mp3"));
        success->setAudioOutput(AudioOutput);
        AudioOutput->setVolume(75);
        success->play();
        if (grid_9 == 'X') {
            player_1_score += 1;
            ui->player_1_score->setText(QString::number(player_1_score));
            ui->winner_label->setText(QString("Player 1 wins!"));
        }
        else if (grid_9 == 'O') {
            player_2_score += 1;
            ui->player_2_score->setText(QString::number(player_2_score));
            ui->winner_label->setText(QString("Player 2 wins!"));
        }
    }
}
