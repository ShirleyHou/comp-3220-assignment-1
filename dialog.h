#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <vector>
#include "game.h"
#include <QDialogButtonBox>
#include <QMediaPlayer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setGames(std::vector<Game*> games);
    void loadGame();

    std::vector<Game*> m_games;
    Game* current_game;
    QTimer *m_timer;
public slots:
    void nextFrame();


protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::Dialog *ui;
    int m_counter;
    int game_selector;


};

#endif // DIALOG_H
