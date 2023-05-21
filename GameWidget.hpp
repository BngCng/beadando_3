#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include "widget_anc.hpp"
#include "Img.hpp"

// Háttér megrajzolása
class GameWidget : public Widget
{
    public:
        GameWidget(int, int);
        void draw();
        void handle(genv::event);
        std::string actual();
        std::string classname();
};

#endif // GAMEWIDGET_HPP
