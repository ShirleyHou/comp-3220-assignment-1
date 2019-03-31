#ifndef PEPPA_EVIL_FACTORY_H
#define PEPPA_EVIL_FACTORY_H
#include <iostream>
#include "factory.h"
#include "stickman.h"
#include "game.h"
#include "asm1game.h"
#include "verticalbackground.h"

/*
 * Concrete factory producing the gangsta peppa game mode (with a vertical scrolling backrgound)
 */

class peppa_evil_factory: public Factory
{
public:
    peppa_evil_factory();
    Background* createBackground(std::string picture_path,
                                 int x_axis,
                                 int y_axis,
                                 int width,
                                 int height,
                                 double velocity){
        return new VerticalBackground(":/resources/img/coin.png",
                                        x_axis,
                                        y_axis,
                                        width,
                                        height,
                                        velocity);
    }
    Character* createCharacter(std::string picture_path,
                               int x_axis,
                               int y_axis,
                               int x_max,
                               int y_max,
                               double x_velocity,
                               double y_velocity,
                               double scale,
                               std::string motion
                               );

    Game* createGame(){
        return new Asm1Game();
    }
};

#endif // PEPPA_EVIL_FACTORY_H
