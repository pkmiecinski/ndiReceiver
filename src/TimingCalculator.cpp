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
    bpmInMs = milisencondsInMinute / bpm;
    barInMs = bpmInMs * 4;
    phraseInMs = barInMs * 4; 
}

uint32_t TimingCalculator::getBarTime()
{
    return barInMs;
}

uint32_t TimingCalculator::getPhraseTime()
{
    return phraseInMs;
}