#include <iostream>
#include "PixelInMatrix.h"
#include "ChannelManager.h"


int PixelInMatrix::setColor(uint8_t redArg, uint8_t greenArg, uint8_t blueArg, uint8_t whiteArg)
{
    red = redArg;
    green = greenArg; 
    blue = blueArg; 
    white = whiteArg;    
    return 0; 
}

int PixelInMatrix::getColor(uint8_t &redArg, uint8_t &greenArg, uint8_t &blueArg, uint8_t &whiteArg)
{
    redArg = red; 
    greenArg = green;
    blueArg = blue;
    whiteArg = white;

    return 0;
}

PixelInMatrix::PixelInMatrix()
{
    red = 0;
    green = 0;
    blue = 0;
    white = 0;
    universe = 0;
    dmx_addr = 0;

}

int PixelInMatrix::setAddress(uint16_t universeArg, uint16_t addrArg)
{   
    universe = universeArg;
    dmx_addr = addrArg;
    
    cm->addDeviceToChannelList(universe,dmx_addr,      &(this->red) );
    cm->addDeviceToChannelList(universe,dmx_addr + 1 , &(this->green) );
    cm->addDeviceToChannelList(universe,dmx_addr + 2 , &(this->blue) );
    cm->addDeviceToChannelList(universe,dmx_addr + 3 , &(this->white) );
}


int PixelInMatrix::getAddress(uint16_t &universeArg, uint16_t &addrArg)
{
    universeArg = universe;
    addrArg = dmx_addr;
}
