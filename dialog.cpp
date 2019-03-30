#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
#include <QTimer>
#include <iostream>
#include "peppafactory.h"
#include "peppagamebuilder.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_counter(0)
{
    game_selector = 0;

}
void Dialog::setGames(std::vector<Game*> games){
    m_games = games;
}
void Dialog::loadGame(){
    ui->setupUi(this);
    current_game = m_games[game_selector%m_games.size()];
    this->resize(current_game->m_background->m_width, current_game->m_background->m_height);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
    m_timer = timer;


}
void Dialog::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    current_game->render(painter, m_counter);
    m_counter++;


}
void Dialog::nextFrame()
{
    update();

}


Dialog::~Dialog()
{
    for (auto game : m_games)
        delete game;
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    if (m_timer->isActive()){
        cout<<"paused"<<endl;
        m_timer->stop();
    }else{
        cout<<"resumed"<<endl;
        m_timer->start();
    }

}

void Dialog::on_pushButton_2_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/resources/sound/peppa.mp3"));
    music->play();

    game_selector+=1;
    current_game = m_games[game_selector%m_games.size()];
}
