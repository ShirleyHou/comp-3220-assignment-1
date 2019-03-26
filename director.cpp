#include "director.h"
using namespace std;


Director::Director(GameBuilder* concrete_builder, Factory* factory, ConfigManager* cm):
    my_builder(concrete_builder),
    my_factory(factory)
{
    my_builder->game_factory = my_factory;
    m_size = Size::NORMAL;
    m_bg_speed = 2;
    m_bg_path = ":/resources/img/peppa_bg.jpg";
    m_cm = cm;
};

Game* Director::makeGame(){

    Game* new_game = my_builder->getGame();
    new_game->m_characters=my_builder->buildCharacters(m_cm->character_settings);
    new_game->m_background=my_builder->buildBackground(m_bg_path, m_bg_speed);
    return new_game;
};
