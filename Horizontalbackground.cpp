#include "horizontalbackground.h"

using namespace std;

HorizontalBackground::HorizontalBackground(string picture_path, int x_axis, int y_axis, int width, int height, double velocity):
    Background (picture_path, x_axis,y_axis,width, height, velocity, 0)
{}

bool HorizontalBackground::repeat(){

    return get_x_axis() > get_width();
}
void HorizontalBackground::render(QPainter &painter, int m_counter)
{
    int m_x_axis = get_x_axis();

    int m_y_axis = get_y_axis();
    int m_height = get_height();
    int m_width = get_width();
    double m_x_velocity = get_x_velocity();
    QPixmap m_QPixmap = *get_pixmap();


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
    set_x_axis(m_x_axis+m_x_velocity);
}

