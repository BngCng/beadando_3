#include "Img.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;




void Img::draw() // adott kep kirajzolsasara valo fuggveny
{
    for(int x=0; x<_size_x; x++)
    {
        for(int y=0; y<_size_y; y++)
        {
            gout << move_to(x+_x,y+_y) << color(img[x][y].r,img[x][y].g,img[x][y].b) << dot;
        }
    }
}

void Img::handle(event ev)
{}


Img::Img(int x,int y, string filename) : _x(x), _y(y), _filename(filename) // beolvasas a konstruktorban
{
    ifstream is;
    is.open(filename);
    if (!is.good())
    {
        cerr << endl << "Fatal error: could not find '" << filename << "' in the game directory.";
        exit(1);
    }
    is >> _size_x >> _size_y;
    cout << "loading " << filename << " (" << _size_x << "x" <<_size_y << ") ..." << endl;
    img = vector<vector<pix>>(_size_x, vector<pix>(_size_y, pix(0,255,0)));

    for(int y=0; y < _size_y; y++)
    {
        for(int x=0; x<_size_x; x++)
        {
            int r,g,b;
            is >> r >> g >> b;
            pix p(r,g,b);
            img[x][y] = p;
        }
    }
    cout << "loading successful!" << endl;
}

string Img::actual()
{
    return _filename;
}

string Img::classname()
{
    return "image";
}
