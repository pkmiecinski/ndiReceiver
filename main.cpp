#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <random>
#include "ChannelManager.h"
#include "ndiReceiverWrapper.h"
#include "TimingCalculator.h"
#include "ArtnetManager.h"
#include "PixelMatrix.h"

#include <boost/thread/thread.hpp>
#include "boost/multi_array.hpp"


class ChannelManager;
ChannelManager* cm;


int main(int argc, char* argv[])
{	
    TimingCalculator tc;
    uint16_t bpm = 1;

    if (argc > 1)
    {
        bpm = atoi(argv[1]);
    }

    tc.setBpm(bpm);


	int universe = 0;
    uint8_t dmx_data[numberOfChannelsInUniverse + 1];

    ArtnetManager* am = new ArtnetManager();
    am->Initialize(0);
    am->Start();

    cm = new ChannelManager();

    // Orgaqnize small rgbw pixel matrix (4,4)
    PixelMatrix pm(4,4);
    pm.setAddress(1);

    // Set the dimmer value to 200
    pm.dim->setAddress(0,65);
    pm.dim->setValue(200);

    // connect fixtures to ChannelManager
    pm.patchPixels();

    // prepare random number generator
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(20, 255);







    NdiReceiver recv;
    recv.initialize();
    recv.captureInLoop();
    recv.cleanup();



    return 0;
}
