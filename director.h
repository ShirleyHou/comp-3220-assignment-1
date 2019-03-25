#ifndef DIRECTOR_H
#define DIRECTOR_H


#include "factory.h"
#include "gamebuilder.h"
#include "game.h"

class Director{
public:
    Director(GameBuilder* concrete_builder, Factory* factory):
        my_builder(concrete_builder),
        my_factory(factory)
    {
        my_builder->game_factory = my_factory;
    };

    Game* makeGame(){
        return my_builder->getGame();
    };
    ~Director(){}
private:
    GameBuilder* my_builder;
    Factory* my_factory;
};

#endif // DIRECTOR_H
