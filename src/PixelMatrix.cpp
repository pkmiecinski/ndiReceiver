#include <iostream>
#include "PixelMatrix.h"




PixelMatrix::PixelMatrix(int size_x_arg, int size_y_arg) : px(boost::extents[size_x_arg][size_y_arg])
{   
    numerOfChannelsPerPixel = 4; 
    size_x = size_x_arg;
    size_y = size_y_arg;
    dim = new Dimmer(0);
}

int PixelMatrix::addAllPixels()
{
    px[0][0].setAddress(0, dmxStartAddress);
}

int PixelMatrix::setAddress(uint16_t dmxAddrArg)
{
    dmxStartAddress = dmxAddrArg;
}

int PixelMatrix::setColor(uint16_t x, uint16_t y, uint8_t redArg, uint8_t greenArg, uint8_t blueArg, uint8_t whiteArg)
{
    px[x][y].setColor(redArg, greenArg, blueArg, whiteArg);
}

int PixelMatrix::patchPixels()
{
    //patch pixels to dmx 
    for(int i = 0 ; i < size_x; i++)
        for(int j = 0 ; j < size_y; j++)
        {
            px[i][j].setAddress(0,dmxStartAddress + i*size_x*size_y + j*numerOfChannelsPerPixel);
        }

    dim->setAddress(0,163);

}


int PixelMatrix::dumpMatrix()
{
    uint8_t red=0, green=0, blue=0, white=0;
    uint16_t universe=0, dmx_address=0;

    for (int indx = 0; indx < size_x; indx++)
        for (int indy = 0; indy < size_y; indy++)
        {
            px[indx][indy].getColor(red, green, blue, white);
            px[indx][indy].getAddress(universe, dmx_address);
            std::cout << "PX("<<indx<<","<<indy<<") = "<<"("<<unsigned(red)<<","<<unsigned(green)<<","<<unsigned(blue)<<","<<unsigned(white)<<") ";
            std::cout << "unv: "<<universe<<" addr: "<<dmx_address<<std::endl;
        }
}
