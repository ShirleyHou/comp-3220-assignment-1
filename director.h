#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <fstream>
#include <vector>

#include "factory.h"
#include "gamebuilder.h"
#include "configmanager.h"
#include "game.h"


using namespace std;


class Director{
public:
    Director(GameBuilder* concrete_builder, Factory* factory, ConfigManager* cm);
    Game* makeGame(std::string music);
    ~Director(){}
private:
    GameBuilder* my_builder;
    Factory* my_factory;
    std::string m_bg_path;
    int m_bg_speed;
    ConfigManager* m_cm;
};

#endif // DIRECTOR_H
