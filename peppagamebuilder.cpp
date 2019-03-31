#include "peppagamebuilder.h"

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
        Character* new_character = game_factory->createCharacter(
                    cfg->image_path,
                    cfg->x_position,
                    cfg->y_position,
                    cfg->x_max,
                    cfg->y_max,
                    cfg->x_velocity,
                    0,
                    scale,
                    cfg->motion);
        characters.push_back(new_character);
    }
    return characters;

};
Background* PeppaGameBuilder::buildBackground(std::string path, int width, int height, int x_speed){

    Background* background = game_factory->createBackground(path,0,0,width, height, x_speed);

    return background;

};

QMediaPlaylist * PeppaGameBuilder::setMusic(std::string music_url){

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl(music_url.c_str()));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    return playlist;
}
Game* PeppaGameBuilder::getGame(){
    Game* new_game(game_factory->createGame());
    return new_game;
};

