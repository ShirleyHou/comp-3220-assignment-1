#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
#include <QTimer>
#include <iostream>
#include "peppafactory.h"
#include "peppagamebuilder.h"
#include <QDialogButtonBox>
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

    this->resize(m_game->m_background->m_width, m_game->m_background->m_height);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
    m_timer = timer;


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
