#include "character.h"
Character::Character(std::string picture_path,
          int x_axis,
          int y_axis,
         int x_max,
         int y_max,
          double x_velocity,
          double y_velocity,
          double user_scale,
          std::string motion):
    Image(picture_path, x_axis, y_axis, x_velocity, y_velocity=0)
{
    int width = get_width();
    int height = get_height();

    if (std::max(width, height) > 300){
        double pre_scale = (double)300/(double) std::max(width, height);
        set_width(pre_scale * (double) width);
        set_height(pre_scale * (double) height);
    }

    set_width(user_scale * (double) get_width());
    set_height(user_scale * (double) get_height());
    //scale = user_scale;
}

//double Character::get_scale() const {return scale;}
//void Character::set_scale(double user_scale){scale = user_scale;}
