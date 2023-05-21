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
    int focusw = -1;
    int focust = 0;

    vector<Widget*> widgets;
    vector<Tank*> players;

    GameWidget* current = new GameWidget(1200, 900); //jatekter megrajzolasa
    current->draw();
    gout.refresh();

    Tank* player1 = new Tank(138,460,1,"p1tank.kep","Player #1");
    players.push_back(player1);
    Tank* player2 = new Tank(920,460,-1,"p2tank.kep","Player #2");
    players.push_back(player2);

    for(Tank* p : players)
        {
            p->drawinit();
        }
    gout.refresh();



    // Widgetek letrehozasa, vektorba helyezese---------------------
    spinbox* sp1 = new spinbox(400,600,200,100,45,0,70,"°");
    widgets.push_back(sp1);
    spinbox* sp2 = new spinbox(800,600,200,100,1,1,10,"");
    widgets.push_back(sp2);


    players[1]->handling = false; //a masodik jatekost nem kezeljuk.

    while(gin >> ev && ev.keycode != key_escape) // van bemenet, fut a fõ program
    {
        if(ev.type == ev.button && ev.keycode == key_space)
        {
            players[focust]->handling = false;
            if(focust == 0) focust = 1;
            else focust = 0;
            players[focust]->handling = true;
            cout << "fokusz:" << focust << endl;
        }
            sp1->_num = players[focust]->incline;
            //sp2->_num = players[focust]->force;

        if (ev.type == ev_mouse && ev.button==btn_left) // ha kattintunk
        {
            focusw = -1; //levesszuk a fokuszbol a widgetet
            for (size_t i=0;i<widgets.size();i++) // fókuszba helyezzük a kattintott widgetet, ha van
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focusw = i;
                }
            }
        }
        if (focusw!=-1) //kezeljük a fókuszált widgetet
        {
            widgets[focusw]->handle(ev);
        }

        for (Widget * w : widgets) // kirajzoljuk a megjelenítendõ widgeteket
        {
            w->draw();
        }

        player1->drawturret(0,0,0, 92, 27);
        player2->drawturret(0,0,0, 48, 27);

        players[focust]->incline = sp1->_num; //a tankok szamlaloi atveszik az ertekeket
        players[focust]->force = sp1->_num;


        player1->drawturret(195,195,195, 92, 27);
        player2->drawturret(154,96,65, 48, 27);

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
