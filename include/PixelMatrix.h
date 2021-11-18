#include <iostream>
#include "Dimmer.h"
#include "PixelInMatrix.h"
#include "boost/multi_array.hpp"

class PixelMatrix
{
public:
    PixelMatrix(int size_x_arg, int size_y_arg);
    int setAddress(uint16_t dmxAddrArg);
    int setColor(uint16_t x, uint16_t y, uint8_t redArg, uint8_t greenArg, uint8_t blueArg, uint8_t whiteArg);
    int dumpMatrix();
    int addAllPixels();
    int patchPixels();

    Dimmer *dim;

private:
    uint16_t dmxStartAddress; 
    typedef boost::multi_array<PixelInMatrix, 2> array_type;
    typedef array_type::index index;
    array_type px;
    
    
    uint8_t numerOfChannelsPerPixel;
    uint16_t size_x;
    uint16_t size_y; 

};
