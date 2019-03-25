#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H
#include "game.h"
#include "factory.h"
#include <vector>

class GameBuilder{
public:
    GameBuilder(){};
    virtual std::vector<Character*> buildCharacters()=0;
    virtual Background* buildBackground()=0;
    virtual Game* getGame() = 0;
    virtual ~GameBuilder(){}

    Factory* game_factory;
};
#endif // GAMEBUILDER_H
