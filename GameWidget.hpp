#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include "widget_anc.hpp"

// Grafikus megjelenítésért felelõs komponens
class GameWidget : public Widget
{
    public:
        GameWidget();

    protected:
        struct pix //pixel felepitese
{
    unsigned char r,g,b;
    pix(int rr, int gg, int bb) : r(rr), g(gg), b(bb){}
};


    private:
};

#endif // GAMEWIDGET_HPP
