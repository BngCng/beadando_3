#ifndef IMG_HPP
#define IMG_HPP

#include "widget_anc.hpp"
#include <vector>

using namespace std;

class Img : public Widget
{
    protected:
        int _x, _y, _size_x, _size_y;
        string _filename;
        struct pix //pixel felepitese
        {
            unsigned char r,g,b;
            pix(int rr, int gg, int bb) : r(rr), g(gg), b(bb){}
        };
        vector<vector<pix>> img;

    public:
        Img(std::string);
        Img();
        void draw();
        void handle(genv::event);
        std::string actual();
        std::string classname();
};

#endif // IMG_HPP
