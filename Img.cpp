#include "Img.hpp"

Img::Img()
{
    ifstream is;
    is.open(filename);
    if (!is.good())
    {
        cerr << endl << "Fatal error: could not find '" << filename << "' in the game directory.";
        exit(1);
    }
    is >> imgx >> imgy;
    cout << "loading " << filename << " (" << imgx << "x" <<imgy << ") ..." << endl;
    img = vector<vector<pix>>(imgx, vector<pix>(imgy, pix(0,255,0)));

    for(int y=0; y < imgy; y++)
    {
        for(int x=0; x<imgx; x++)
        {
            int r,g,b;
            is >> r >> g >> b;
            pix p(r,g,b);
            img[x][y] = p;
        }
    }
    cout << "loading successful!" << endl;
}

Img::~Img()
{
    //dtor
}
