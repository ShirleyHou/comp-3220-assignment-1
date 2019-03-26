#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include "game.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setGame(Game* game);
    void loadGame();

    Game* m_game;
    QTimer *m_timer;
public slots:
    void nextFrame();


protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int m_counter;


};

#endif // DIALOG_H
