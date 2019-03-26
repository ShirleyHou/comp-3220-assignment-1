#ifndef HORIZONTALBACKGROUND_H
#define HORIZONTALBACKGROUND_H

#include "background.h"
class HorizontalBackground:public Background{
public:
    HorizontalBackground(std::string picture_path, int x_axis, int y_axis, double velocity=0);
    virtual ~HorizontalBackground(){}
    void render(QPainter &painter, int m_counter);
    bool repeat();
    std::string tell();
};

#endif // HORIZONTALBACKGROUND_H
