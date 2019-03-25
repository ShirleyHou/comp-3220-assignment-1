#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include "background.h"
#include "character.h"
#include <vector>
class Game
{
public:
    Game(){}
    Game(Background* background, std::vector<Character*> characters):
        m_background(background),
        m_characters(characters)
    {}
    virtual ~Game(){
        delete m_background;
        for (auto& character:m_characters){
            delete character;
        }
    }
    virtual void render(QPainter &painter, int m_counter)=0;
    Background* m_background = nullptr;
    std::vector<Character*> m_characters = std::vector<Character*>();

};

#endif // GAME_H
