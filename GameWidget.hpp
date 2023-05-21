#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include "widget_anc.hpp"
#include "Img.hpp"

// Grafikus megjelen�t�s�rt felel�s komponens
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
