#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include "widget_anc.hpp"
#include "Img.hpp"

// Grafikus megjelenítésért felelõs komponens
class GameWidget : public Widget
{
    public:
        GameWidget(int, int);
        void draw();
        void handle(genv::event);
        std::string actual();
        std::string classname();
    private:
        Img bgi;
};

#endif // GAMEWIDGET_HPP
