#ifndef SPINBOX_HPP
#define SPINBOX_HPP

#include "widget_anc.hpp"


class spinbox : public Widget
{
    public:
        spinbox(int, int, int, int, int, int, int);
        void draw();
        void handle(genv::event);
        std::string actual();
        std::string classname();

    protected:
        bool handling;
        int minnum, maxnum, _num;
};

#endif // SPINBOX_HPP
