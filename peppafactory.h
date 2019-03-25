#ifndef PEPPAFACTORY_H
#define PEPPAFACTORY_H
#include "factory.h"
#include "stickman.h"
#include "game.h"
#include "asm1game.h"
class PeppaFactory : public Factory{
public:
    Background* createBackground(std::string picture_path, int x_axis, int y_axis, double velocity){
        return new HorizontalBackground(picture_path, x_axis, y_axis, velocity);
    }
    Character* createCharacter(std::string picture_path, int x_axis, int y_axis, double x_velocity, double y_velocity, double scale){
        return new Stickman(picture_path, x_axis, y_axis, scale);
    }

    Game* createGame(){
        return new Asm1Game();
    }

};
#endif // PEPPAFACTORY_H
