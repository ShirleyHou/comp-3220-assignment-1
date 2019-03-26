#include "stickman.h"

Stickman::Stickman(std::string picture_path, int x_axis=0, int y_axis=0, double scale=1.0):
    Character(picture_path, x_axis, y_axis, 0,0,scale)
{}

std::string Stickman::tell(){
    return "I am "+name;
}

void Stickman::render(QPainter &painter, int m_counter)
{

    painter.drawPixmap(m_x_axis,
                       m_y_axis,
                       m_width,
                       m_height,
                       m_QPixmap);
}

