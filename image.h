#ifndef IMAGE_H
#define IMAGE_H

#include <QPainter>

/*
 * Base class for all objects in the game that has a jpeg/png/gif to render.
 * Inherited by abstract character and abstract background.
 * Note: not a part of the abstract factory pattern. Pure inheritance.
 */
class Image{
public:
    Image(std::string picturepath, int x_axis, int y_axis,double x_velocity, double y_velocity);

    virtual ~Image(){
        delete m_QPixmap;
    }

    virtual void render(QPainter &painter, int m_counter)=0;

    void set_picture_path (std::string picture_path);

    int get_width() const;
    int get_height() const;
    int get_x_axis() const;
    int get_y_axis()const;
    double get_x_velocity () const;
    double get_y_velocity()const;
    QPixmap* get_pixmap() const;
    void set_width(int w);
    void set_height(int h);
    void set_x_axis(int x);
    void set_y_axis(int y);
    void set_x_velocity(double x);
    void set_y_velocity(double y);
private:
    int m_width;
    int m_height;
    int m_x_axis;
    int m_y_axis;

    QPixmap* m_QPixmap;
    double m_x_velocity;
    double m_y_velocity;

};

#endif // IMAGE_H
