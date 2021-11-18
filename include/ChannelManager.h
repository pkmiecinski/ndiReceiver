#ifndef CHANNEL_MANAGER_H
#define CHANNEL_MANAGER_H

#include <iostream>
#include "DeviceDefines.h"

class ChannelManager
{
    public:
        ChannelManager();

        // To be finished, not to use right now
        int addDeviceToChannelList(uint16_t universe, uint16_t address, uint8_t* deviceParameter);
        int prepareData(uint16_t universe, uint8_t* dmx_data);
        int dumpValues(int universe);

        int setDmxChannelValue(uint8_t value);

        uint8_t* channelPointers [numberOfUniverses][numberOfChannelsInUniverse+1];


    private:
        uint8_t dummy_value;
};

#endif