#include <iostream>
#include "ArtnetManager.h"

#include <artnet/artnet.h>


int ArtnetManager::Initialize(uint8_t universe)
{

    node = artnet_new("192.168.1.203", 0);
    artnet_set_short_name(node, "ArtNet console");
    artnet_set_long_name(node, "ArtNet console");
    artnet_set_node_type(node, ARTNET_SRV);
    artnet_set_port_type(node, 0, ARTNET_ENABLE_INPUT, ARTNET_PORT_DMX);
    artnet_set_port_addr(node, 0, ARTNET_INPUT_PORT, universe);
    
    return 0;
}

int ArtnetManager::Start()
{
    artnet_start(node) ;
    return 0;
}

int ArtnetManager::SendToUniverse(uint8_t universe, uint8_t* dmx_data, uint16_t data_size )
{
    // sending from 1 index instead of 0 to resolve dmx indexing from 1 nonsense
    artnet_send_dmx(node, 0, data_size, dmx_data+1);   
}