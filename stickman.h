#ifndef STICKMAN_H
#define STICKMAN_H

#include "character.h"
class Stickman: public Character
{
public:
    Stickman(std::string picture_path, int x_axis, int y_axis, double scale, std::string motion);
    virtual ~Stickman(){}
    std::string tell();
    void render(QPainter &painter, int m_counter);
    std::string name;
private:
    double m_y_delta;
    double m_y_amplitude;
    double m_y_frequency;
    double m_y_shift;
};

#endif // STICKMAN_H
