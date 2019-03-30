#ifndef PEPPAGAMEBUILDER_H
#define PEPPAGAMEBUILDER_H
#include "gamebuilder.h"
#include "factory.h"
#include <vector>
#include "size.h"
#include "configmanager.h"
class PeppaGameBuilder:public GameBuilder{
public:
    PeppaGameBuilder(){}
    std::vector<Character*> buildCharacters(vector<Character_config*> cfgs)override;
    Background* buildBackground(std::string image_path, int speed)override;
    Game* getGame()override;
    QMediaPlaylist * setMusic(std::string music_url)override;
    virtual ~PeppaGameBuilder()override{}

};

#endif // PEPPAGAMEBUILDER_H
