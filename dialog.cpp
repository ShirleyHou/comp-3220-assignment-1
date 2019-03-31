
#include <QTimer>
#include <iostream>
#include "dialog.h"
#include "ui_dialog.h"


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

/*
 * Initialise the dialog's rendering with a choosen first game.
 *
 */
void Dialog::loadGame(){
    ui->setupUi(this);
    current_game = m_games[game_selector%m_games.size()];
    this->resize(current_game->get_background()->get_width(), current_game->get_background()->get_height());


    m_music->setPlaylist(current_game->get_playlist());
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

/*
 * Botton handler for "play/palse".
 *
 */
void Dialog::on_pushButton_clicked()
{

    if (m_timer->isActive()){
        std::cout<<"paused"<<std::endl;
        m_timer->stop();
        m_music->pause();
    }else{
        std::cout<<"resumed"<<std::endl;
        m_timer->start();
        m_music->play();
    }

}

/*
 * Botton handler for "swag".
 *
 */
void Dialog::on_pushButton_2_clicked()
{

    m_music->stop();
    game_selector+=1;

    std::vector<int> x_positions;
    for (auto c:current_game->get_characters())
        x_positions.push_back(c->get_x_axis());

    std::reverse(x_positions.begin(),x_positions.end());
    current_game = m_games[game_selector%m_games.size()];

    for (auto c:current_game->get_characters()){
        c->set_x_axis(x_positions.back());
        x_positions.pop_back();
    }

    m_music->setPlaylist(current_game->get_playlist());
    m_music->play();
}

