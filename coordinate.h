#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:
    Coordinate(unsigned int xCoordinate,
               unsigned int yCoordinate,
               unsigned int frameWidth,
               unsigned int frameHeight
               );
    int getQtRenderingXCoordinate();
    int getQtRenderingYCoordinate();
    void changeInXCoordinate(int change);
    void changeInYCoordinate(int change);
    void setYCoordinateToZero(int offset);
    void setXCoordinateToRightFrame(int offset);
    unsigned int getFrameHeight();
    unsigned int getFrameWidth();
private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_frameHeight;
    unsigned int m_frameWidth;
};

#endif // COORDINATE_H
