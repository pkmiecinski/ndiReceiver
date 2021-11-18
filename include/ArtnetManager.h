#include <iostream>
#include <artnet/artnet.h>

#include "DeviceDefines.h"

class ArtnetManager
{
    public:
        ArtnetManager(){}
        int Initialize(uint8_t universe);
        int Start();
        int SendToUniverse(uint8_t universe, uint8_t* dmx_data, uint16_t data_size );

    private:
        artnet_node node;

};
