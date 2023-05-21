#include "GameWidget.hpp"
#include "graphics.hpp"
#include "Img.hpp"
#include <iostream>

// x es y mindig 0 kell hogy legyen
GameWidget::GameWidget(int sx, int sy) : Widget(0,0,sx, sy)
{
    genv::gout.open(_size_x,_size_y);
    genv::gout.load_font("LiberationSans-Regular.ttf",12);
}

void GameWidget::draw()
{
    Img bgi(_x,_y,"background.kep");
    bgi.draw();
}

void GameWidget::handle(genv::event ev)
{

}

std::string GameWidget::actual()
{
    return "returns background image";
}

std::string GameWidget::classname()
{
    return "GameWidget";
}
