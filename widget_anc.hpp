#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "graphics.hpp"


class Widget {
protected:
    int _x, _y, _size_x, _size_y;
public:
    Widget(int x, int y, int sx, int sy);
    Widget(int sx, int sy);
    Widget();
    virtual ~Widget()
    {

    };
    //virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual std::string actual() = 0;
    virtual std::string classname() = 0;
};

#endif // WIDGET_HPP
