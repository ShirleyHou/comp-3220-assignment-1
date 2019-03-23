#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_background(Background(Coordinate(0,0,1920, 558),5, 0)),
    m_counter(0)
{
    ui->setupUi(this);
    this->update();
    this->resize(1920, 558);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
}
void Dialog::nextFrame()
{
    update();
}
void Dialog::paintEvent(QPaintEvent *event)
{
    bool animation = true;
        if (animation) {
            // code for this exercise goes here

            QPainter painter(this);
            m_background.render(painter, m_counter);
            QPixmap man(":/resources/img/man.gif");
            painter.drawPixmap(1000,258,200,200,man);
            m_counter++;
        }

}

Dialog::~Dialog()
{
    delete ui;
}
