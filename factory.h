#ifndef FACTORY_H
#define FACTORY_H



#include "background.h"
#include "character.h"
#include "game.h"
/*
 * A part of abstract factory structure: the Abstract Factory Interface.
 * inherited by one or more concrete factory that needs to implement the following functions:
 *
 * createBackground: returns a background object.
 * createCharacter: returns a character object.
 * createGame: returns a game object.
 */
class Factory{
public:

    virtual ~Factory(){}
    virtual Background* createBackground(std::string picture_path,
                                         int x_axis,
                                         int y_axis,
                                         int width,
                                         int height,
                                         double velocity)=0;
    virtual Character* createCharacter(std::string picture_path,
                                       int x_axis,
                                       int y_axis,
                                       int x_max,
                                       int y_max,
                                       double x_velocity,
                                       double y_velocity,
                                       double scale,
                                       std::string motion)=0;
    virtual Game* createGame()=0;
};



#endif // FACTORY_H
