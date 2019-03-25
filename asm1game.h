#ifndef ASM1GAME_H
#define ASM1GAME_H
#include "game.h"

class Asm1Game: public Game{
public:
    Asm1Game();
    virtual ~Asm1Game(){};
    Asm1Game(Background* background, std::vector<Character*> characters);
    void render(QPainter &painter, int m_counter);
};

#endif // ASM1GAME_H
