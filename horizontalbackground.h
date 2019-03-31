#ifndef HORIZONTALBACKGROUND_H
#define HORIZONTALBACKGROUND_H

#include "background.h"

/*
 * concrete horizontal background inherits from the abstract Background.
 * A part of the Abstract Factory Design Pattern.
 * As a special background type, it only has velocity in the x direction
 */
class HorizontalBackground:public Background{
public:
    HorizontalBackground(std::string picture_path, int x_axis, int y_axis, int width, int height, double velocity=0);
    virtual ~HorizontalBackground()override{}
    void render(QPainter &painter, int m_counter)override;
    bool repeat()override;

};

#endif // HORIZONTALBACKGROUND_H
