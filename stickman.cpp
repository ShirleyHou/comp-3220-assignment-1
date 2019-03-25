#include "stickman.h"

Stickman::Stickman(std::string picture_path, int x_axis, int y_axis, double scale):
    Character(picture_path, x_axis, y_axis, 0,0,scale)
{}

std::string Stickman::tell(){
    return "I am a stickman!";
}

void Stickman::render(QPainter &painter, int m_counter)
{

    painter.drawPixmap(m_x_axis,
                       m_y_axis,
                       m_width,
                       m_height,
                       m_QPixmap);
}

