#ifndef VERTICALBACKGROUND_H
#define VERTICALBACKGROUND_H

#include "background.h"

/*
 * concrete vertical background inherits from the abstract Background.
 * A part of the Abstract Factory Design Pattern.
 * As a special background type, it only has velocity in the y direction
 */
class VerticalBackground:public Background{
public:
    VerticalBackground(std::string picture_path, int x_axis, int y_axis, int width, int height, double velocity=0);
    virtual ~VerticalBackground()override{}
    void render(QPainter &painter, int m_counter)override;
    bool repeat()override;

};


#endif // VERTICALBACKGROUND_H
