#include "peppa_evil_factory.h"

peppa_evil_factory::peppa_evil_factory(){}

Character* peppa_evil_factory::createCharacter(std::string picture_path,
                           int x_axis,
                           int y_axis,
                           int x_max,
                           int y_max,
                           double x_velocity,
                           double y_velocity,
                           double scale,
                           std::string motion
                           ){
    std::size_t pos = picture_path.find(".png");
    std::string evil_path = picture_path.substr(0,pos)+"_gangsta.png";
    return new Stickman(evil_path, x_axis, y_axis, x_max, y_max, x_velocity, scale,motion);
}
