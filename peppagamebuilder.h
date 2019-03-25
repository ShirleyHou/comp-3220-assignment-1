#ifndef PEPPAGAMEBUILDER_H
#define PEPPAGAMEBUILDER_H
#include "gamebuilder.h"
#include "factory.h"
#include <vector>
class PeppaGameBuilder:public GameBuilder{
public:
    PeppaGameBuilder(){};
    std::vector<Character*> buildCharacters();
    Background* buildBackground();
    Game* getGame();
    virtual ~PeppaGameBuilder(){};

};

#endif // PEPPAGAMEBUILDER_H
