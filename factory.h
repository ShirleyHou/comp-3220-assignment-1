#ifndef FACTORY_H
#define FACTORY_H

#include <QPainter>
#include <vector>
#include "background.h"
#include "horizontalbackground.h"
#include "character.h"
#include "stickman.h"
#include "game.h"
#include "asm1game.h"
class Factory{
public:

    virtual ~Factory(){}
    virtual Background* createBackground(std::string picture_path, int x_axis, int y_axis, double velocity)=0;
    virtual Character* createCharacter(std::string picture_path, int x_axis, int y_axis, double x_velocity, double y_velocity, double scale)=0;
    virtual Game* createGame()=0;
};



#endif // FACTORY_H
