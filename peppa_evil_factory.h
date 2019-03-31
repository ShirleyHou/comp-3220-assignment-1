#ifndef PEPPA_EVIL_FACTORY_H
#define PEPPA_EVIL_FACTORY_H
#include <iostream>
#include "factory.h"
#include "stickman.h"
#include "game.h"
#include "asm1game.h"
#include "horizontalbackground.h"


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
        return new HorizontalBackground(picture_path,
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
                               ){
        std::size_t pos = picture_path.find(".png");
        std::string evil_path = picture_path.substr(0,pos)+"_gangsta.png";
//        std::cout <<evil_path<<std::endl;
        return new Stickman(evil_path, x_axis, y_axis, x_max, y_max, x_velocity, scale,motion);
    }

    Game* createGame(){
        return new Asm1Game();
    }
};

#endif // PEPPA_EVIL_FACTORY_H
