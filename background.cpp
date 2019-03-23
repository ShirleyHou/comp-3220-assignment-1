#include "background.h"
#include <iostream>
using namespace std;
Background::Background(Coordinate coordinate):
    m_coordinate(coordinate),
    m_xVelocity(1),
    m_yVelocity(1)
    {};
Background::Background(Coordinate coordinate,
    double xVelocity,
    double yVelocity):
    m_coordinate(coordinate),
    m_xVelocity(xVelocity),
    m_yVelocity(yVelocity)
    {};

bool Background::isCollisionHorizontal(){
    return m_coordinate.getQtRenderingXCoordinate() >
            (signed int) (m_coordinate.getFrameWidth());
}

void Background::render(QPainter &painter, unsigned int time)
{
    if (isCollisionHorizontal()) {
            m_coordinate.setXCoordinateToRightFrame(0);


        }

    cout << m_coordinate.getFrameWidth()<<" "<<m_coordinate.getFrameHeight() <<endl;
    QPixmap pix(":/resources/img/peppa_bg.jpg");
    painter.drawPixmap(m_coordinate.getQtRenderingXCoordinate(),
                       m_coordinate.getQtRenderingYCoordinate(),
                       1920,558, pix);
    painter.drawPixmap(m_coordinate.getQtRenderingXCoordinate()-1920,
                       m_coordinate.getQtRenderingYCoordinate(),
                       1920,558, pix);

    m_coordinate.changeInXCoordinate(m_xVelocity);
    m_coordinate.changeInYCoordinate(m_yVelocity);

}
