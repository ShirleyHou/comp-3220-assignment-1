#ifndef STICKMAN_H
#define STICKMAN_H

#include "character.h"

/*
 * A part of abstract factory structure: the concrete Product that inherits the abstract Character Class
 *
 * the stickman also has a random oscillating y velocity. This velocity can be set by changing the "motion"
 * tag in the config file to either "Fast" or "On".
 *
 * To enable the "motion", the user need to make sure there are 3 or more png files for the stickman to render its
 * animation.
 * named in the convention "<picture_name>.png",  "<picture_name>1.png" and "<picture_name>2.png".
 *
 * despite the stickman has a x-velocity, it will not move outside of the user specified background width,
 * it will bounce back and forward instead.
 *
 */

class Stickman: public Character
{
public:
    Stickman(std::string picture_path, int x_axis, int y_axis, int x_max,
             int y_max, int x_velocity, double scale, std::string motion);
    virtual ~Stickman()override{
        for (auto epa:extra_pixmaps_for_animation)
            delete epa;
    }

    void render(QPainter &painter, int m_counter) override;
    bool repeat();
    int get_x_max() const;
    int get_y_max() const;
private:
    double m_y_delta;
    double m_y_amplitude;
    double m_y_frequency;
    double m_y_shift;
    int m_x_max;
    int m_y_max;
    std::vector<QPixmap*> animated_pixmaps;
    std::vector<QPixmap*> extra_pixmaps_for_animation;
};

#endif // STICKMAN_H
