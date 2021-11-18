#ifndef PIXEL_IN_MATRIX_H
#define PIXEL_IN_MATRIX_H

#include <iostream>
#include "ChannelManager.h"


extern ChannelManager* cm;

class PixelInMatrix
{
public:
    PixelInMatrix();
    int setColor(uint8_t redArg, uint8_t greenArg, uint8_t blueArg, uint8_t whiteArg);
    int setAddress(uint16_t universeArg, uint16_t addrArg);
    int getColor(uint8_t &redArg, uint8_t &greenArg, uint8_t &blueArg, uint8_t &whiteArg);
    int getAddress(uint16_t &universeArg, uint16_t &addrArg);

private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t white;
    uint16_t universe;
    uint16_t dmx_addr;

};

#endif