#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "image.h"
#include <QPainter>
#include <iostream>

/*
 * A part of abstract factory structure: the Abstract Product: Backgroud.
 * inherited by one or more concrete Background that needs to implement the following functions:
 *
 * repeat: redecides if it is necessary to triger repositioning the x or y position
 * inorder to implement the continuous scrolling effect.
 */
class Background: public Image{
public:

    Background(std::string picture_path, int x_axis, int y_axis, int width, int height, double x_velocity, double y_velocity);

    virtual ~ Background(){}
    bool virtual repeat()=0;//could be horizontal or vertically repeat!

};

#endif // BACKGROUND_H

