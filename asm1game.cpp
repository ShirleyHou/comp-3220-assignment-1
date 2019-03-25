#include "asm1game.h"
Asm1Game::Asm1Game():
    Game()
{}
Asm1Game::Asm1Game(Background* background, std::vector<Character*> characters):
    Game(background, characters)
{}
void Asm1Game::render(QPainter &painter, int m_counter){
    m_background->render(painter, m_counter);
    for(auto& character:m_characters){
        character->render(painter, m_counter);
    }
}
