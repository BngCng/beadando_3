#include "Tank.hpp"
#include "Img.hpp"
#include "graphics.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace genv;




Tank::Tank(int x, int y, int d, string in, string n)
: Widget(x,y,0,0), _imgname(in), name(n), direction(d)
{

}

Tank::~Tank(){}

void Tank::drawinit()
{
    cout << "tankertekek" << _x << " " << _y << endl;
    Img tanki(_x,_y,_imgname);

    tanki.draw();
}

void Tank::draw()
{

}

void Tank::handle(event ev)
{

}

void Tank::drawturret(int r, int g, int b, int sx, int sy)
{
    gout << move_to(_x+sx,_y+sy) << color(r,g,b) << line(direction*lx*cos(incline)-ly*sin(incline),lx*sin(incline)+ly*cos(incline));
    if(previncline != incline)
    {
        lx = gout.x();
        ly = gout.y();
        previncline = incline;
    }

}

void Tank::drawhpbar(int x, int y, int hp)
{
    gout << color(100,100,100);
    if(handling) gout << color(255,255,255);
    gout << move_to(x,y) << text(name);
    gout << color(0,255,0);
    if(hp < 76) gout << color(255,255,0);
    if(hp < 51) gout << color(255,165,0);
    if(hp < 26) gout << color(255,0,0);
    gout << move_to(x,y+80) << box(hp*2,30);
}

string Tank::actual()
{
    return "debug";
}

string Tank::classname()
{
    return "Tank";
}

