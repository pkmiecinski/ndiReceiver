#include <cstring>
#include <iostream>
#include <iomanip>
#include "ChannelManager.h"

ChannelManager::ChannelManager()
{
    dummy_value = 0;
    for (int i=0; i<numberOfUniverses; i++)
        for(int j=0; j<numberOfChannelsInUniverse;j++)
            channelPointers[i][j] = &dummy_value;
    
}

int ChannelManager::addDeviceToChannelList(uint16_t universe, uint16_t address, uint8_t* deviceParameter)
{
    channelPointers[universe][address] = deviceParameter;
    return 0;
}

int ChannelManager::dumpValues(int universe)
{
    std::cout<<std::setw(3);
    
    for(int i=0; i<numberOfChannelsInUniverse; i++)
    {
        if (!(i%32))
        {
            std::cout<<std::endl;
            std::cout<<std::setw(3)<<i;
        }

        std::cout<< std::setw(3) << std::right << unsigned(*(channelPointers[universe][i])) <<"|";
    }
    return 0;
}

int ChannelManager::prepareData(uint16_t universe, uint8_t* dmx_data)
{
    for(int i=0; i<numberOfChannelsInUniverse; i++)
    {
        dmx_data[i] = *(channelPointers[universe][i]);
    }

    return 0;
}