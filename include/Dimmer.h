#include <iostream>
#include  "ChannelManager.h"

extern ChannelManager* cm;

class Dimmer
{
    public:
        Dimmer();
        Dimmer(uint8_t dimmerArg);
        Dimmer(uint8_t dimmerArg, uint8_t dimmerFineArg);
        int setAddress(uint16_t universeArg, uint16_t addrArg);
        int setAddress(uint16_t universeArg, uint16_t addrArg, uint16_t addrFineArg);

        int setValue(uint8_t val);
        uint8_t getValue();

    private:
        uint8_t dim_value;
        uint8_t dim_value_fine;
};