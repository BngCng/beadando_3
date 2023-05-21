#include "GameWidget.hpp"
#include "graphics.hpp"
#include "Img.hpp"

// x es y mindig 0 kell hogy legyen
GameWidget::GameWidget(int sx, int sy) : Widget(0,0,sx, sy)
{
    genv::gout.open(_size_x,_size_y);
    genv::gout.load_font("LiberationSans-Regular.ttf",12);
    bgi = Img("background.kep");
}

void GameWidget::draw()
{
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
