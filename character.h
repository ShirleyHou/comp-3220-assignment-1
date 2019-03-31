#ifndef CHARACTER_H
#define CHARACTER_H

#include "image.h"

/*
 * A part of abstract factory structure: the Abstract Product: Character
 * inherited by one or more concrete Stickman/SwagStickman.
 *
 * feature: automatically handles large input image.(if the input file is too big, prescale to 300*300)
 *
 */

class Character: public Image{
public:

    Character(std::string picture_path,
              int x_axis,
              int y_axis,
              int x_max,
              int y_max,
              double x_velocity,
              double y_velocity,
              double scale,
              std::string motion);


    virtual ~Character(){}


};

#endif // CHARACTER_H
