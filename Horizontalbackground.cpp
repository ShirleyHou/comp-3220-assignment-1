#include "horizontalbackground.h"
#include <iostream>
using namespace std;

HorizontalBackground::HorizontalBackground(string picture_path, int x_axis, int y_axis, double velocity):
    Background (picture_path, x_axis,y_axis,velocity, 0)
{}

bool HorizontalBackground::repeat(){

    return m_x_axis > m_width;
}
void HorizontalBackground::render(QPainter &painter, int m_counter)
{
    if (repeat()) {
        m_x_axis = 0;
    }

    painter.drawPixmap(m_x_axis,
                       m_y_axis,
                       m_width,
                       m_height,
                       m_QPixmap);
    painter.drawPixmap(m_x_axis - m_width,
                       m_y_axis,
                       m_width,
                       m_height,
                       m_QPixmap);
    painter.drawPixmap(m_x_axis + m_width,
                       m_y_axis,
                       m_width,
                       m_height,
                       m_QPixmap);
    m_x_axis+=m_x_velocity;
}
std::string HorizontalBackground::tell(){
    return "I am a Horizontal Background!";
}
