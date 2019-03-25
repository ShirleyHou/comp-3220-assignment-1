#include "peppagamebuilder.h"

//PeppaGameBuilder::PeppaGameBuilder(Factory * factory):
//    GameBuilder(factory)
//{};
#include <iostream>
std::vector<Character*> PeppaGameBuilder::buildCharacters(){

    Character* peppa = game_factory->createCharacter(":/resources/img/man.gif",1000,258,0,0,1.0);
    std::vector<Character*> characters;
    characters.push_back(peppa);
    return characters;

};
Background* PeppaGameBuilder::buildBackground(){
    Background* background = game_factory->createBackground(":/resources/img/peppa_bg.jpg",0,0,10.0);
    return background;

};
Game* PeppaGameBuilder::getGame(){
    Game* new_game(game_factory->createGame());
    new_game->m_background = buildBackground();
    new_game->m_characters = buildCharacters();
    std::cout <<"Built peppa game"<<std::endl;
    return new_game;
};

