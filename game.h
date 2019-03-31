#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QMediaPlaylist>

#include "background.h"
#include "character.h"
#include <vector>
/*
 * A part of abstract factory structure:
 * Abstract product of "Game".
 * Needs to be initialized by a background, a vector of characters.
 * Stores the music for that specific game to loop on.
 * also handles the delete of its nested components: background, character, music
 *
 * public:
 *  Game(),
 *  ~Game(),
 *  abstract render,
 *  getters and setters for its private variables.
 *
 * private:
 *  Background* m_background
    std::vector<Character*> m_characters
    QMediaPlaylist *m_playlist
 */
class Game
{
public:
    Game(){}
    Game(Background* background, std::vector<Character*> characters):
        m_background(background),
        m_characters(characters)
    {}
    //handles deletion when game ends.
    virtual ~Game(){
        delete m_background;
        for (auto& character:m_characters){
            delete character;
        }
    }
    virtual void render(QPainter &painter, int m_counter)=0;

    //getter
    Background* get_background () const{ return m_background;}
    std::vector<Character*> get_characters () const{return m_characters;}
    QMediaPlaylist * get_playlist()const{return m_playlist;}

    //setter
    void set_background (Background* bg) {m_background = bg;}
    void set_characters (std::vector<Character*> Chars){ m_characters= Chars;}
    void set_playlist(QMediaPlaylist * qmp){m_playlist = qmp;}

private:
    Background* m_background = nullptr;
    std::vector<Character*> m_characters = std::vector<Character*>();
    QMediaPlaylist *m_playlist;
};

#endif // GAME_H
