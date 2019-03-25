#ifndef IMAGE_H
#define IMAGE_H

#include <QPainter>

class Image{
public:
    Image(std::string picturepath, int x_axis, int y_axis, double x_velocity, double y_velocity):
        m_x_axis(x_axis),
        m_y_axis(y_axis),
        m_x_velocity(x_velocity),
        m_y_velocity(y_velocity)
    {
        set_picture_path(picturepath);
        m_width = m_QPixmap.width();
        m_height = m_QPixmap.height();
    }

    virtual ~Image(){}

    int m_width;
    int m_height;
    int m_x_axis;
    int m_y_axis;

    QPixmap m_QPixmap;
    double m_x_velocity;
    double m_y_velocity;
    virtual void render(QPainter &painter, int m_counter)=0;

    virtual void set_picture_path(std::string picture_path){
        const char *cstr = picture_path.c_str();
        QString filename(cstr);
        QPixmap newPicture(filename);
        m_QPixmap = newPicture;
    }

};

#endif // IMAGE_H
