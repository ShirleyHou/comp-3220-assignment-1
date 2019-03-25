#ifndef STICKMAN_H
#define STICKMAN_H

#include "character.h"
class Stickman: public Character
{
public:
    Stickman(std::string picture_path, int x_axis, int y_axis, double scale);
    virtual ~Stickman(){}
    std::string tell();
    void render(QPainter &painter, int m_counter);
};

#endif // STICKMAN_H
