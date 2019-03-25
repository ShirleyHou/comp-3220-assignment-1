#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "image.h"
#include <QPainter>
#include <iostream>
class Background: public Image{
public:

    Background(std::string picture_path, int x_axis, int y_axis, double x_velocity, double y_velocity):
        Image(picture_path, x_axis, y_axis, x_velocity, y_velocity)
    {
        if (std::max(m_width,m_height)>1000){
            double scale = (double)1000/(double)std::max(m_width,m_height);
            m_width = scale*(double)m_width;
            m_height = scale*(double)m_height;
            std::cout <<"rescaled to "<<m_width<<" "<<m_height<<std::endl;
        }
    };

    virtual ~ Background(){}
    bool virtual repeat()=0;//could be horizontal or vertically repeat!

};

#endif // BACKGROUND_H

//    int get_x_axis();
//    int get_y_axis();
//    void set_x_axis(int target);
//    void set_y_axis(int target);

//    double get_x_velocity();
//    double get_y_velocity();
//    void set_x_velocity(double target);
//    void set_y_velocity(double target);

//    int get_width();
//    int get_height();
//    void set_width(int target);
//    void set_height(int target);


    //QString get_picture_path();
//    QPixmap get_Pixmap();
