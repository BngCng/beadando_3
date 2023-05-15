#ifndef MENU_HPP
#define MENU_HPP

#include "widget_anc.hpp"
#include <vector>


class Menu : public Widget
{
    public:
        Menu(int, int, size_t);
        void draw();
        void handle(genv::event);
        std::string classname(); //kiirashoz
        std::string actual(); //kiirashoz

    protected:
        size_t _size;
        bool handling;
        std::vector<bool> menuitems;
        //a menupontokat kulon strukturaval es szabadon valaszthato menupontokkal kellett volna megoldanom, de sajnos keson alltam neki a feladatnak..

};

#endif // MENU_HPP
