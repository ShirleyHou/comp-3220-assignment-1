#include "background.h"
Background::Background(std::string picture_path,
                       int x_axis,
                       int y_axis,
                       int width,
                       int height,
                       double x_velocity,
                       double y_velocity):
    Image(picture_path, x_axis, y_axis, x_velocity, y_velocity)
{
    set_width(width);
    set_height(height);
};
