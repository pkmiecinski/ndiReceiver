#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <random>
#include <thread>


#include "ChannelManager.h"
#include "ndiReceiverWrapper.h"
#include "TimingCalculator.h"
#include "ArtnetManager.h"
#include "PixelMatrix.h"
#include "DeviceDefines.h"

#include <boost/thread/thread.hpp>
#include "boost/multi_array.hpp"


using namespace std::chrono;


class ChannelManager;
ChannelManager* cm;


const uint32_t ledmatrixWidth = 4;
const uint32_t ledmatrixHeight = 4;


int main(int argc, char* argv[])
{	
    TimingCalculator tc;
    uint16_t bpm = 140; 
    ;

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
    PixelMatrix pm(ledmatrixWidth,ledmatrixHeight);
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

    uint16_t msToWait = tc.getBeatTime();

    NdiReceiver *recv = new NdiReceiver();
    recv->initialize();
    recv->setOutputSize(ledmatrixWidth, ledmatrixHeight);

    std::thread ndiCaptureThread(&NdiReceiver::captureInLoop, recv, "NDI Video Capture Thread");

    auto syncTime = high_resolution_clock::now().time_since_epoch();

    while(1)
    {
        for (int i = 0; i < ledmatrixWidth; i++)
            for (int j = 0; j < ledmatrixHeight;j++)
            {
                pm.setColor(i,j,recv->getOutputPixelValueRed(i,j),
                                recv->getOutputPixelValueGreen(i,j),
                                recv->getOutputPixelValueBlue(i,j),
                                0);


            }

        cm->prepareData(0, dmx_data);
        am->SendToUniverse(0, dmx_data, numberOfChannelsInUniverse );
        syncTime = high_resolution_clock::now().time_since_epoch();
        std::cout<<"sync: "<<std::chrono::duration_cast<std::chrono::milliseconds>(syncTime).count() << std::endl;
        boost::this_thread::sleep( boost::posix_time::milliseconds(msToWait));
    }

    ndiCaptureThread.join();


    recv->cleanup();



    return 0;
}
