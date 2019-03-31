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
//    int width = get_width();
//    int height = get_height();
    set_width(width);
    set_height(height);
//    if (std::max(width,height)>1000){
//        double scale = (double)1000/(double)std::max(width,height);
//        set_width(scale*(double)width);
//        set_height(scale*(double)height);
//        std::cout <<"rescaled to "<<get_width()<<" "<<get_height()<<std::endl;
//    }
};
