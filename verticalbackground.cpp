#include "verticalbackground.h"

using namespace std;

VerticalBackground::VerticalBackground(string picture_path, int x_axis, int y_axis, int width, int height, double velocity):
    Background (picture_path, x_axis,y_axis,width, height, 0, velocity)
{}

bool VerticalBackground::repeat(){

    return get_y_axis() > get_height();
}
void VerticalBackground::render(QPainter &painter, int m_counter)
{
    int m_x_axis = get_x_axis();

    int m_y_axis = get_y_axis();
    int m_height = get_height();
    int m_width = get_width();
    double m_y_velocity = get_y_velocity();
    QPixmap m_QPixmap = *get_pixmap();


    if (repeat()) {
        m_y_axis = 0;
    }

    painter.drawPixmap(m_x_axis,
                       m_y_axis,
                       m_width,
                       m_height,
                       m_QPixmap);
    painter.drawPixmap(m_x_axis,
                       m_y_axis - m_height,
                       m_width,
                       m_height,
                       m_QPixmap);
    painter.drawPixmap(m_x_axis,
                       m_y_axis + m_height,
                       m_width,
                       m_height,
                       m_QPixmap);
    set_y_axis(m_y_axis+m_y_velocity);
}

