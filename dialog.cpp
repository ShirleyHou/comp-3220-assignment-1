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
}
void Dialog::setGame(Game* game){
    m_game = game;
}
void Dialog::loadGame(){
    ui->setupUi(this);
//    int smaller_size = m_background->m_width
    this->resize(m_game->m_background->m_width, m_game->m_background->m_height);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

}
void Dialog::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    m_game->render(painter, m_counter);
    m_counter++;


}
void Dialog::nextFrame()
{
    update();

}

Dialog::~Dialog()
{

    delete m_game;
    delete ui;
}
