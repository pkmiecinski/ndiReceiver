#include <iostream>
#include "Dimmer.h"


Dimmer::Dimmer()
{
    dim_value = 0;
}

Dimmer::Dimmer(uint8_t dimmerArg)
{
    this->dim_value = dimmerArg;
}

Dimmer::Dimmer(uint8_t dimmerArg, uint8_t dimmerFineArg)
{
    this->dim_value = dimmerArg;
    this->dim_value_fine = dimmerFineArg;
}

int Dimmer::setAddress(uint16_t universeArg, uint16_t addrArg)
{
    cm->addDeviceToChannelList(universeArg,addrArg, &(this->dim_value) );

    return 0;
}

int Dimmer::setAddress(uint16_t universeArg, uint16_t addrArg, uint16_t addrFineAddr)
{
    cm->addDeviceToChannelList(universeArg,addrArg,      &(this->dim_value) );
    cm->addDeviceToChannelList(universeArg,addrFineAddr, &(this->dim_value_fine) );

    return 0;
}

int Dimmer::setValue(uint8_t val)
{
    dim_value = val;
    return 0;
}

uint8_t Dimmer::getValue()
{
    return dim_value;
}