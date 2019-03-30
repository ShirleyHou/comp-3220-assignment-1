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
    m_music = new QMediaPlayer();
    game_selector = 0;

}
void Dialog::setGames(std::vector<Game*> games){
    m_games = games;

}
void Dialog::loadGame(){
    ui->setupUi(this);
    current_game = m_games[game_selector%m_games.size()];
    this->resize(current_game->m_background->m_width, current_game->m_background->m_height);


    m_music->setPlaylist(current_game->m_playlist);
    m_music->play();


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(50);
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
        m_music->pause();
    }else{
        cout<<"resumed"<<endl;
        m_timer->start();
        m_music->play();
    }

}

void Dialog::on_pushButton_2_clicked()
{
//    QMediaPlayer * music = new QMediaPlayer();
//    music->setMedia(QUrl("qrc:/resources/sound/swag.mp3"));
//    music->play();
    m_music->stop();
    game_selector+=1;
    current_game = m_games[game_selector%m_games.size()];
    m_music->setPlaylist(current_game->m_playlist);
    m_music->play();
}

