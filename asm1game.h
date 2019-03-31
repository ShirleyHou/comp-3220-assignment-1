#ifndef ASM1GAME_H
#define ASM1GAME_H
#include "game.h"

/*
 * concrete product inherits from the abstract Game.
 * A part of the Abstract Factory Design Pattern.
 */
class Asm1Game: public Game{
public:
    Asm1Game();
    virtual ~Asm1Game() override {}
    Asm1Game(Background* background, std::vector<Character*> characters);
    void render(QPainter &painter, int m_counter)override;


};

#endif // ASM1GAME_H
