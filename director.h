#ifndef DIRECTOR_H
#define DIRECTOR_H


#include "factory.h"
#include "gamebuilder.h"
#include "configmanager.h"
#include "game.h"
#include "size.h"
#include <fstream>
#include <vector>
using namespace std;


class Director{
public:
    Director(GameBuilder* concrete_builder, Factory* factory, ConfigManager* cm);
    Game* makeGame(std::string music);
    ~Director(){}
private:
    GameBuilder* my_builder;
    Factory* my_factory;
    Size m_size;
    std::string m_bg_path;
    int m_bg_speed;
    ConfigManager* m_cm;
};

#endif // DIRECTOR_H
