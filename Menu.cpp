#include "Menu.hpp"
#include "graphics.hpp"

using namespace genv;

Menu::Menu(int x, int y, size_t s) : Widget(x,y,150,s*50), _size(s)
{
    for(int i=0; i<_size; i++) //a kijeloles-indikator vektor feltoltese menupontnyi hamis logikai ertekkel
    {
        menuitems.push_back(false);
    }
}

std::string Menu::actual() //kiirashoz
{
    return "<poor code error>";
}
std::string Menu::classname() //kiirashoz
{
    return "Menu";
}

void Menu::draw()
{
    gout << color(255,0,0);
    if(handling) gout << color(0,255, 0);

    gout << move_to(_x,_y) << box(_size_x,_size_y);

    for(int i=0;i<_size;i++)
    {
        gout << move_to(_x + 2, _y + 2 + i*50) << color(0,0,0);
        if(menuitems[i]) gout << color(0,255,0);
        gout << box(_size_x - 4, 46)
        << move_to(_x + 15, _y + 15 + i*50) << color(255,0,0)
        << font("LiberationSans-Regular.ttf",20) << text("Menupont ") << text(std::to_string(i));
    }

    handling = false;
}

void Menu::handle(event ev)
{
    if(ev.button == btn_left) // a kattintas valamely menupont felett van-e
    {
        for(int i=0; i<_size ;i++)
        {
            if(ev.pos_x > _x + 2 && ev.pos_x < _x + _size_x -2
               && ev.pos_y >= _y + 2 + i*50 && ev.pos_y <= _y + 2 + (i+1)*50)
               {
                   menuitems[i] = true;
               }
            else menuitems[i] = false;
        }
    }

    handling = true;
}

