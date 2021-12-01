#include "TimingCalculator.h"


TimingCalculator::TimingCalculator()
{

}

TimingCalculator::TimingCalculator(uint16_t argBpm)
{

}

int TimingCalculator::setBpm(uint16_t argBpm)
{
    bpm = argBpm;

    std::cout << bpmInMs << std::endl;
    bpmInMs = milisencondsInMinute / bpm;
    barInMs = bpmInMs * 4;
    
    phraseInMs = barInMs * 4; 
    std::cout << phraseInMs << std::endl;
}

uint32_t TimingCalculator::getBeatTime()
{
    return bpmInMs;
}


uint32_t TimingCalculator::getBarTime()
{
    return barInMs;
}

uint32_t TimingCalculator::getPhraseTime()
{
    return phraseInMs;
}