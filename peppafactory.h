#ifndef PEPPAFACTORY_H
#define PEPPAFACTORY_H
#include "horizontalbackground.h"
#include "factory.h"
#include "stickman.h"
#include "game.h"
#include "asm1game.h"

/*
 * Concrete factory producing the normal peppa game mode (with a horizontal scrolling background)
 */
class PeppaFactory : public Factory{
public:
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
        return new Stickman(picture_path, x_axis, y_axis, x_max, y_max, x_velocity, scale,motion);
    }

    Game* createGame(){
        return new Asm1Game();
    }

};
#endif // PEPPAFACTORY_H
