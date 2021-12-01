#include <iostream>
#include "DeviceDefines.h"

class TimingCalculator
{
    public:
        TimingCalculator(uint16_t argBpm);
        TimingCalculator();
        int setBpm(uint16_t argBpm);
        uint32_t getBeatTime();
        uint32_t getBarTime();
        uint32_t getPhraseTime();

    private:
        uint16_t bpm;
        uint16_t bpmInMs;
        uint32_t barInMs;
        uint32_t phraseInMs;

        const uint16_t milisencondsInMinute = 60000;
};
