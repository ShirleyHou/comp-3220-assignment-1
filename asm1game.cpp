#include "asm1game.h"
Asm1Game::Asm1Game():
    Game()
{}
Asm1Game::Asm1Game(Background* background, std::vector<Character*> characters):
    Game(background, characters)
{}

void Asm1Game::render(QPainter &painter, int m_counter){
    Background* background = get_background();
    std::vector<Character*> characters = get_characters();

    //render background before rendering characters
    background->render(painter, m_counter);
    for(auto& c:characters){
        c->render(painter, m_counter);
    }
}
