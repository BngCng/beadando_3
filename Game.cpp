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
#include "Tank.hpp"

using namespace genv;
using namespace std;

Game::Game()
{
    program();
}

int Game::program() {

    event ev;
    gin.timer(20);
    int focus = -1;

    vector<Widget*> widgets;
    vector<Tank*> players;

    GameWidget* current = new GameWidget(1200, 900); //jatekter megrajzolasa
    current->draw();
    gout.refresh();

    Tank* player1 = new Tank(138,460,1,"p1tank.kep","Player #1");
    players.push_back(player1);
    Tank* player2 = new Tank(846,460,-1,"p2tank.kep","Player #2");
    players.push_back(player2);
    gout.refresh();

    for(Tank* p : players)
    {
        p->drawinit();
    }

    // Widgetek letrehozasa, vektorba helyezese---------------------
    spinbox* sp1 = new spinbox(400,600,200,100,45,0,70,"°");
    widgets.push_back(sp1);
    spinbox* sp2 = new spinbox(800,600,200,100,0,1,10,"");
    widgets.push_back(sp2);




    while(gin >> ev && ev.keycode != key_escape) // van bemenet, fut a fõ program
    {

        for (Widget * w : widgets) // kirajzoljuk a megjelenítendõ widgeteket
        {
            w->draw();
            w->handle(ev);
        }


        for (Tank * p : players)
        {

        }
        player1->drawhpbar(20,570,100);
        player2->drawhpbar(20,770,50);


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
