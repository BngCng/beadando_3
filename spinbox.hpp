#ifndef SPINBOX_HPP
#define SPINBOX_HPP

#include "widget_anc.hpp"


class spinbox : public Widget
{
    public:
        spinbox(int, int, int, int, int, int, int, std::string);
        void draw();
        void handle(genv::event);
        std::string actual();
        std::string classname();

    protected:
        bool handling;
        int minnum, maxnum, _num;
        std::string unit;
};

#endif // SPINBOX_HPP
