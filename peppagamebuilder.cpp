#include "peppagamebuilder.h"

//PeppaGameBuilder::PeppaGameBuilder(Factory * factory):
//    GameBuilder(factory)
//{};
#include <iostream>
std::vector<Character*> PeppaGameBuilder::buildCharacters(vector<Character_config*> cfgs){

    //add another method to build individual characters

    std::vector<Character*> characters;
    for (auto& cfg:cfgs){
        double scale = 1.0;
        if (cfg->size_str=="TINY"){
            scale = 0.5;
        }else if (cfg->size_str=="LARGE"){
            scale = 1.5;
        }else if (cfg->size_str=="GIANT"){
            scale = 2.0;
        }
        Character* new_character = game_factory->createCharacter(cfg->image_path,cfg->x_position,cfg->y_position,0,0,scale, cfg->motion);
        characters.push_back(new_character);
    }
    return characters;

};
Background* PeppaGameBuilder::buildBackground(std::string path, int x_speed){
    //":/resources/img/peppa_bg.jpg"
    Background* background = game_factory->createBackground(path,0,0,x_speed);
    return background;

};
Game* PeppaGameBuilder::getGame(){
    Game* new_game(game_factory->createGame());
    return new_game;
};

