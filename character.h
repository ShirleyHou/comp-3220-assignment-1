#ifndef CHARACTER_H
#define CHARACTER_H


#include "image.h"
#include <QPainter>

class Character: public Image{
public:

    Character(std::string picture_path, int x_axis, int y_axis, double x_velocity, double y_velocity, double scale):
        Image(picture_path, x_axis, y_axis, x_velocity=0, y_velocity=0)
    {
        if (std::max(m_width,m_height)>300){
            double scale = (double)300/(double)std::max(m_width,m_height);
            m_width = scale*(double)m_width;
            m_height = scale*(double)m_height;
            //std::cout <<"rescaled to "<<m_width<<" "<<m_height<<std::endl;
        }

        m_width = scale*m_width;
        m_height = scale*m_height;
    }

    virtual ~Character(){};
    double scale;

};

#endif // CHARACTER_H
