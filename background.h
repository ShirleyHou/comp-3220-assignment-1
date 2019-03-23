#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "coordinate.h"
#include <QPainter>

class Background
{
public:
    Background(Coordinate coordinate);
    Background(Coordinate, double xVelocity, double yVelocity);
    ~Background(){};
    void render(QPainter &painter, unsigned int time);
    bool isCollisionHorizontal();
private:
    Background();
    Coordinate m_coordinate;
    double m_xVelocity;
    double m_yVelocity;
};

#endif // BACKGROUND_H
