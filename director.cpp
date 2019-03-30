#include "director.h"
using namespace std;


Director::Director(GameBuilder* concrete_builder, Factory* factory, ConfigManager* cm):
    my_builder(concrete_builder),
    my_factory(factory)
{
    my_builder->game_factory = my_factory;
    m_size = Size::NORMAL;
    m_bg_speed = cm->m_background_velocity;
    m_bg_path = cm->m_background_path;
    m_cm = cm;
};

Game* Director::makeGame(std::string music){

    Game* new_game = my_builder->getGame();
    new_game->m_characters=my_builder->buildCharacters(m_cm->character_settings);
    new_game->m_background=my_builder->buildBackground(m_bg_path, m_bg_speed);
    new_game->m_playlist = my_builder->setMusic(music);
    return new_game;
};
