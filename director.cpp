#include "director.h"
using namespace std;


Director::Director(GameBuilder* concrete_builder, Factory* factory, ConfigManager* cm):
    my_builder(concrete_builder),
    my_factory(factory)
{
    my_builder->game_factory = my_factory;
    m_cm = cm;
};

Game* Director::makeGame(std::string music){

    Game* new_game = my_builder->getGame();
    new_game->set_characters(my_builder->buildCharacters(m_cm->character_settings));
    new_game->set_background(my_builder->buildBackground(m_cm->m_background_path,
                                                       m_cm->m_background_width,
                                                       m_cm->m_background_height,
                                                       m_cm->m_background_velocity));
    new_game->set_playlist(my_builder->setMusic(music));
    return new_game;
};
