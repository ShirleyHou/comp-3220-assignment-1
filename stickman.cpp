
#include <QtMath>
#include <QRandomGenerator>

#include "stickman.h"


Stickman::Stickman(std::string picture_path, int x_axis=0, int y_axis=0, int x_max=2000,
                   int y_max = 2000, int x_velocity =0,  double scale=1.0, std::string motion="OFF"):
    Character(picture_path, x_axis, y_axis, x_max, y_max, x_velocity,0,scale, motion)
{
    m_y_delta = 0;
    m_y_amplitude = 0;
    m_y_frequency=5;
    m_y_shift = qrand() % 10;
    m_x_max = x_max;
    m_y_max = y_max;
    int height = get_height();

    QPixmap * pixmap = get_pixmap();
    std::vector<QPixmap*> animated;
    animated.push_back(pixmap);
    animated_pixmaps = animated;

    if (motion!="OFF"){
        m_y_amplitude = height/15;
        std::string name = picture_path.substr(0,picture_path.find(".png"));
        std::string animation_2 = name+"1.png";
        std::string animation_3 = name+"2.png";

        QPixmap* motion2 = new QPixmap(animation_2.c_str());
        QPixmap* motion3 = new QPixmap(animation_3.c_str());

        animated_pixmaps.push_back(motion2);
        animated_pixmaps.push_back(motion3);
        animated_pixmaps.push_back(motion2);
        animated_pixmaps.push_back(pixmap);
        extra_pixmaps_for_animation.push_back(motion2);
        extra_pixmaps_for_animation.push_back(motion3);

    }
    if (motion=="FAST"){
        m_y_frequency=1;
    }
}

bool Stickman::repeat(){
    return (get_x_axis() > m_x_max||get_x_axis()<0);
}
int Stickman::get_x_max() const {return m_x_max;}
int Stickman::get_y_max() const {return m_y_max;}

void Stickman::render(QPainter &painter, int m_counter)
{
    if (repeat()){
        set_x_velocity(-1*get_x_velocity());

    }
    m_y_delta = qSin((m_counter-m_y_shift)/(m_y_frequency+0.1))*m_y_amplitude;
    int x_axis = get_x_axis();
    int y_axis = get_y_axis();
    int width = get_width();
    int height = get_height();
    painter.drawPixmap(x_axis,
                       y_axis+m_y_delta,
                       width,
                       height,
                       *animated_pixmaps[m_counter%animated_pixmaps.size()]);
    set_x_axis(x_axis+get_x_velocity());
}

