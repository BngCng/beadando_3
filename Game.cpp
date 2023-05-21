#include "graphics.hpp"
#include "widget_anc.hpp"
#include "spinbox.hpp"
#include "Menu.hpp"
#include "extendedmenu.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include "Game.hpp"
#include "GameWidget.hpp"

using namespace genv;
using namespace std;

Game::Game()
{
    GameWidget tankgame(1200, 900);
    vector<Widget*> widgets;
    spinbox* sp1 = new spinbox(10,10,100,50,42,40,50);
    widgets.push_back(sp1);
    spinbox* sp2 = new spinbox(10,65,200,70,0,-10,10);
    widgets.push_back(sp2);

    program(widgets);
}

int Game::program(vector<Widget*>& widgets) {
    event ev;
    gin.timer(20);
    int focus = -1;

    while(gin >> ev && ev.keycode != key_escape) // van bemenet, fut a fõ program
    {
        /*if (ev.type == ev_mouse && ev.button==btn_left) // ha kattintunk
        {
            focus = -1; //levesszuk a fokuszbol a widgetet
            for (size_t i=0;i<widgets.size();i++) // fókuszba helyezzük a kattintott widgetet, ha van
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (focus!=-1) //kezeljük a fókuszált widgetet
        {
            widgets[focus]->handle(ev);
        }*/
        for (Widget * w : widgets) // kirajzoljuk a megjelenítendõ widgeteket
        {
            w->draw();
            w->handle(ev);
        }
        if(ev.keycode == key_lctrl) // filebaírás a bal ctrl megnyomása esetén
        {
            ofstream os;
            os.open("check.txt");
            os << "---check---" << endl;
            int i = 0;
            for(Widget * w : widgets)
            {
                i++;
                os << "widget " << i << " " << w->classname() << " " << w->actual() << " " << endl;
            }
        }
        gout << refresh;
    }
    return 0;
}
