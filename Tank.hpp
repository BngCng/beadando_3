#ifndef TANK_HPP
#define TANK_HPP

#include "widget_anc.hpp"
#include "Img.hpp"


class Tank : public Widget
{
    public:
        Tank(int, int, int, std::string, std::string);
        virtual ~Tank();
        void draw();
        void drawinit();
        void drawturret(int, int, int, int, int);
        void drawhpbar(int,int,int);
        void handle(genv::event);
        std::string name = "";
        bool handling;
        std::string actual();
        std::string classname();
        int incline = 0;
        int previncline = 0;
        int force = 5;
        int tex,tey; // cso vegenek rajzpontja a lovedekhez

    private:
        std::string _imgname;
        int direction; //a tank iranya; -1,ha balra, 1, ha jobbra nez
        int lx = 40;
        int ly = 0;
};

#endif // TANK_HPP
