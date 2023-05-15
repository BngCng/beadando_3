#include "spinbox.hpp"
#include "graphics.hpp"

using namespace genv;

spinbox::spinbox(int x, int y, int sx, int sy, int num, int mini, int maxi) : Widget(x,y,sx,sy),_num(num),minnum(mini),maxnum(maxi)
{

}

void spinbox::draw()
{
    gout << move_to(_x,_y) << color(255,0,0);
    if(handling) gout << color(0,255,0);
    gout << box(_size_x,_size_y)
    << move_to(_x + 2, _y + 2) << color(0,0,0) << box(_size_x - 4, _size_y -4) << color(255,0,0);
    if(handling) gout << color(0,255,0);
    gout << move_to(_x + _size_x - (_size_x / 3), _y) << line(0,_size_y)
    << move(0,-(_size_y / 2)) << line(_size_x / 3,0) << line(-(_size_x / 6), -(_size_y / 2))
    << line(-(_size_x / 6), (_size_y / 2)) << line((_size_x / 6), (_size_y / 2)) << line((_size_x / 6), -(_size_y / 2))

    << move_to(_x + _size_x/20, _y + _size_y/4) << font("LiberationSans-Regular.ttf",_size_y / 2) << text(std::to_string(_num));
    handling = false;
}

void spinbox::handle(event ev)
{
    handling = true;
    if((ev.button == btn_left && ev.pos_x >= _x + _size_x/3*2 && ev.pos_x <= _x + _size_x
        && ev.pos_y <= _y + _size_y/2 && ev.pos_y >= _y)|| ev.keycode == key_up)
    {
        if(_num < maxnum)_num ++;
    }
    if((ev.button == btn_left && ev.pos_x >= _x + _size_x/3*2 && ev.pos_x <= _x + _size_x
        && ev.pos_y >= _y + _size_y/2 && ev.pos_y <= _y + _size_y)|| ev.keycode == key_down)
    {
        if(_num > minnum)_num --;
    }
    if(ev.keycode == key_pgup)
    {
        for(int i=0; i<10; i++)
        {
            if(_num < maxnum) _num ++;
        }
    }
    if(ev.keycode == key_pgdn)
    {
        for(int i=0; i<10; i++)
        {
            if(_num > minnum) _num --;
        }
    }
}

std::string spinbox::actual() //kiirashoz
{
    return std::to_string(_num);
}
std::string spinbox::classname() //kiirashoz
{
    return "spinbox";
}


