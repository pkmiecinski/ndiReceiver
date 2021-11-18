#include <iostream>

#include <Processing.NDI.Lib.h>
#include <opencv2/opencv.hpp>

class NdiReceiver 
{
    public:
        NdiReceiver();
        int initialize();
        int cleanup();
        int captureInLoop();

    private:

    NDIlib_recv_instance_t pNDI_recv;

    const std::uint16_t  frameWidth = 1920;
    const std::uint16_t  frameHigh  = 1080;
    const std::uint8_t   pixelSize = 4;

};

