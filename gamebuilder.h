#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H
#include "game.h"
#include "factory.h"
#include <vector>
#include "configmanager.h"

/*
 * Abstract Builder Interface
 */
class GameBuilder{
public:

    virtual std::vector<Character*> buildCharacters(vector<Character_config*> cfgs)=0;
    virtual Background* buildBackground(std::string image_path, int width, int height, int speed)=0;
    virtual Game* getGame() = 0;
    virtual QMediaPlaylist * setMusic(std::string music_url)=0;
    virtual ~GameBuilder(){}

    Factory* game_factory;
};
#endif // GAMEBUILDER_H
