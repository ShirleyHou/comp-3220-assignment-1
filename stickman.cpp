#include "stickman.h"
#include <QtMath>
#include <QRandomGenerator>
Stickman::Stickman(std::string picture_path, int x_axis=0, int y_axis=0, double scale=1.0, std::string motion="OFF"):
    Character(picture_path, x_axis, y_axis, 0,0,scale, motion)
{
    m_y_delta = 0;
    m_y_amplitude = 0;
    m_y_frequency=5;
    m_y_shift = qrand() % 10;

    if (motion!="OFF"){
        m_y_amplitude = m_height/15;
    }
    if (motion=="FAST"){
        m_y_frequency=1;
    }
}

std::string Stickman::tell(){
    return "I am "+name;
}

void Stickman::render(QPainter &painter, int m_counter)
{
    m_y_delta = qSin((m_counter-m_y_shift)/(m_y_frequency+0.1))*m_y_amplitude;
    painter.drawPixmap(m_x_axis,
                       m_y_axis+m_y_delta,
                       m_width,
                       m_height,
                       m_QPixmap);
}

