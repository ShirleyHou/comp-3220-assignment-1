#include "image.h"

/*!
 * Initialize image base object.
 * Background, Character and their concrete child classes all inherit from Image.
 *
 * \param: std::string picture_path: file name (based on resource files) as literal string.
 * \param: int x_axis
 * \param: int y_axis
 * \param: int x_velocity
 * \param: int y_velocity
 */

Image::Image(std::string picture_path, int x_axis, int y_axis, double x_velocity, double y_velocity):
    m_x_axis(x_axis),
    m_y_axis(y_axis),
    m_x_velocity(x_velocity),
    m_y_velocity(y_velocity)
{
    set_picture_path(picture_path);
    m_width = m_QPixmap->width();
    m_height = m_QPixmap->height();
}

/*!
 * set the image's QPixmap object according to the given literal string file path.
 * \param: std::string
 */
void Image::set_picture_path (std::string picture_path){
    const char *cstr = picture_path.c_str();
    QString filename(cstr);
    QPixmap* newPicture = new QPixmap(filename);
    m_QPixmap = newPicture;
}

int Image::get_width() const {return m_width;}

int Image::get_height() const {return m_height;}

int Image::get_x_axis() const {return m_x_axis;}

int Image::get_y_axis()const {return m_y_axis;}

double Image::get_x_velocity () const{return m_x_velocity;}

double Image::get_y_velocity()const{return m_y_velocity;}

QPixmap* Image::get_pixmap() const {return m_QPixmap;}


/*!
 * set image width to int value no smaller than 10
 * \param: int
 */
void Image::set_width(int w) {
    m_width = std::max(w, 10);

}

/*!
 * set image height to int value no smaller than 10
 * \param: int
 */
void Image::set_height(int h) {
    m_height = std::max(h, 10);
}
void Image::set_x_axis(int x) { m_x_axis = x;}

void Image::set_y_axis(int y) { m_y_axis = y;}

void Image::set_x_velocity(double x) { m_x_velocity = x;}

void Image::set_y_velocity(double y) { m_y_velocity = y;}
